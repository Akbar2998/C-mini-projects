#include <iostream>
using namespace std;
template <typename T>
T summ(T a,T b) {
    int last;
    int x;
    if (b>a) {
        x = a;
        a = b;
        b = x;

    }
    if ((a > b) || (a == b)) {
    for(int i = 1; i < min(a,b) + 1; i++) {
        if (a%i == b%i) {
           last = i;
        }
    }
    }
    
    return last;
}



int main() {
   cout << summ(9,6) << endl;
   cout << summ(6,6) << endl;
   cout << summ(10,5) << endl;
   cout << summ(10,15) << endl;
}
