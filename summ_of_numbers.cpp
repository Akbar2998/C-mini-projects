#include <iostream>
using namespace std;
template <typename T>
T summ(T a) {
    int x = 0;
    do {
        x += a%10;
        a = a/10;
    }

    while (a > 0);

    return x;
}



int main() {
   cout << summ(458) << endl;
}
