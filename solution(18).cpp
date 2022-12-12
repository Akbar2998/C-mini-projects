#include <iostream>
#include <sstream>
using namespace std;

#  define TEMPLATE_VOTING
#  define MANIPULATOR_QUOTE
#  define EFFECTOR_DOUBLE_SPACE
#  define TRAITS_MOBILE

#ifdef TEMPLATE_VOTING

template<class T, unsigned N>
class voting {
  T e[N];
  unsigned n[N] = {};
  bool closed = false;
public:
  voting(T (&t)[N]) {
    for (unsigned i = 0; i < N; i++)
      e[i] = t[i];
  }

  voting& operator+=(const T& t) {
    if (closed)
      throw exception();
    for (unsigned i = 0; i < N; i++)
      if (e[i] == t) {
        n[i]++;
        return *this;
      }
    throw exception();
  }

  template<class K>
  voting& operator+=(const K&) {
    throw exception();
  }

  const T& operator!() {
    closed = true;
    unsigned max_index = 0;
    for (unsigned i = 0; i < N; i++)
      if (n[max_index] < n[i])
        max_index = i;
    return e[max_index];
  }

  friend ostream& operator<<(ostream& os, const voting& v) {
    for (unsigned i = 0; i < N; i++)
      os << v.e[i] << ":" << v.n[i] << endl;
    return os;
  }
};

template<unsigned N>
class voting<unsigned, N> {
  typedef unsigned T;
  T e[N];
  unsigned n[N] = {};
  bool closed = false;
public:
  voting(T (&t)[N]) {
    for (unsigned i = 0; i < N; i++)
      e[i] = t[i];
  }
  
  voting& operator+=(const T& t) {
    for (unsigned i = 0; i < N; i++)
      if (e[i] == t) {
        n[i] += t;
        return *this;
      }
    throw exception();
  }
  
  template<class K>
  voting& operator+=(const K&) {
    throw exception();
  }
  
  friend ostream& operator<<(ostream& os, const voting& v) {
    for (unsigned i = 0; i < N; i++)
      os << v.e[i] << ":" << v.n[i] << endl;
    return os;
  }
};

// ----- test -----

void test_voting() {
  cout << endl << "test voting" << endl;

  try {
    int t[5] = { 1, 2, 3, 4, 5};
    voting<int, 5> vt(t);
    ((vt += 1) += 1) += 2;
    cout << vt;
    cout << "winner:" << !vt << endl;

    // spec. unsigned
    unsigned uns[] = {1, 2, 3, 4};
    voting<unsigned, 4> uv(uns);
    uv += 2u;
    uv += 2u;
    cout << uv << endl;

  } catch (const exception& e) {
    cout << "error:" << e.what() << endl;
  }

  try {
    int t[5] = { 1, 2, 3, 4, 5};
    voting<int, 5> vt(t);
    vt += 6;
  } catch (const exception& e) {
    cout << "ok" << endl;
  }

  
}
#endif // TEMPLATE_VOTING



#ifdef MANIPULATOR_QUOTE

ostream& quote(ostream &os) {
  static stringstream ss;
  static ostream *os_other;
  static bool open = true;
  if ((open = !open)) {
    string str(ss.str()), extra;
    if (str.length() <=2 || (str[0] != '"' || str.back() != '"'))
      extra = "\"";
    return (*os_other) << extra << str << extra;
  } else {
    os_other = &os;
    ss.str("");
    return ss;
  }
}
// ----- test -----

void test_quote() {
  cout << endl << "test quote" << endl;
  cout << quote << "text" << quote << endl;
  cout << quote << "\"text\"" << quote << endl;
  cout << quote << " \"text\" " << quote << endl;
}
#endif // MANIPULATOR_QUOTE



#ifdef EFFECTOR_DOUBLE_SPACE

class double_space {
  string s;
public:
  double_space(const string& s) : s(s) {
  }

  friend ostream& operator<<(ostream &os, const double_space &b) {
    for (const auto &c : b.s)
      os << (c == ' ' ?  " " : "") << c;
    return os;
  }
};

// ---------- Test ---------

void test_double_space() {
  cout << endl << "double space test:" << endl;
  cout << double_space("test_without_space\t123") << endl;
  cout << double_space("one space,  two,   three") << endl;
}
#endif // EFFECTOR_DOUBLE_SPACE
 


#ifdef TRAITS_MOBILE


class Android {
  string op_system;
public:
  Android(unsigned version) : op_system("Android v" + to_string(version)) {
  }
  const string& get_op_system() const {
    return op_system;
  }
};

class iOS {
  string op_system;
public:
  iOS(unsigned version) : op_system("iOS v" + to_string(version)) {
  }
  const string& get_op_system() const {
    return op_system;
  }
};

class Hun {
  string lang = "Hungarian";
public:
  const string& get_lang() const {
    return lang;
  }
};

class Eng {
  string lang = "English";
public:
  const string& get_lang() const {
    return lang;
  }
};

class Samsung {
public:
  string get_brand() const {
    return "Samsung";
  }
};

class iPhone {
public:
  string get_brand() const {
    return "iPhone";
  }
};

template<class BRAND>
class mobile_config;

template<>
class mobile_config<Samsung> {
public:
  typedef Android op_system_type;
  typedef Hun lang_type;
};

template<>
class mobile_config<iPhone> {
public:
  typedef iOS op_system_type;
  typedef Eng lang_type;
};

template<class BRAND, class CONFIG = mobile_config<BRAND>, unsigned VER = 10>
class mobile {
  typedef typename CONFIG::op_system_type op_system_type;
  typedef typename CONFIG::lang_type lang_type;
  
  string name;
  BRAND brand;
  op_system_type op_s;
  lang_type lang;
public:
  mobile(const string& name, unsigned op_version = VER) : name(name), op_s(op_version) {
  }
  
  friend ostream& operator<<(ostream& os, const mobile& m) {
    return os << m.name << " (" << m.brand.get_brand() << ", "
              << m.op_s.get_op_system() << ", "
              << m.lang.get_lang() << ")";
  }
  
  const op_system_type& get_os() const {
    return op_s;
  }
};

// ----- test -----

void test_mombile() {
  cout << endl << "test mobile" << endl;

  mobile<Samsung> ma("Samsung X", 11);
  cout << ma << endl;
  cout << ma.get_os().get_op_system() << endl;
  /* Samsung X (Samsung, Android v11, Hungarian)
     Android v11
  */

  mobile<iPhone, mobile_config<iPhone>, 13> mi("iPhone 13");
  cout << mi << endl;
  cout << mi.get_os().get_op_system() << endl;
  /* iPhone 13 (iPhone, iOS v13, English)
     iOS v13
  */
}

#endif // TRAITS_MOBILE



int main() {

#ifdef TEMPLATE_VOTING
  test_voting();
#endif

#ifdef MANIPULATOR_QUOTE
  test_quote();
#endif

#ifdef EFFECTOR_DOUBLE_SPACE
  test_double_space();
#endif

#ifdef TRAITS_MOBILE
  test_mombile();
#endif
}
