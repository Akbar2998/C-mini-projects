#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main(){

    int aniq_son, son1, son2, taxmin;
    srand(time(NULL));
    cout << "                     ********Son topish o'yini************" << "\n";
    cout << "Son 1-oraliqini kiriting: ";
    cin >> son1;
    cout << "Son 2-oraliqini kiriting: ";
    cin >> son2;
    int urinish = 0;
    cout << "Biz son o'yladik va bu son " << son1 << " va " << son2 << "  sonlari orasida joylashgan \n";
    aniq_son = (rand()%son2 + son1);
    do {
        cout << "Taxmin qiling:  \n";
        cin >> taxmin;
        urinish += 1;
        if (taxmin > aniq_son) {
            cout << "Katta! \n" ;}
        else if (taxmin < aniq_son) {
            cout << "Kichik \n";
        }
        else {
            cout << "To'ppa to'gri topdingiz!  " << "\n Urinishlar soni: " << urinish;
        }

    }
    while (taxmin != aniq_son);

  return 0;
}

