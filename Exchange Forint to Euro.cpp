/*Efector: Exchange (6 point)
Write an Exchange eector that takes an unsigned value and a string as its parameters. The
eector converts euro to forint and vice versa. The number parameter represents the amount
of money, the string represents the currency, it can be "EUR" or "HUF". The exchange rate
of the euro should be 425. That is, for an input of 100 EUR, write "42500 HUF" to the output
stream. The conversion from forint to euro should be done with integer division. That is, if the
input is 800 HUF, the output should be "1 EUR". If the string of the currency is not "HUF"
or "EUR", the output written on the stream should be "ERROR". The quotation marks are not
part of the outputs.*/
#include <string>
#include <iostream>
using namespace std;
template <typename T,typename K>
T Exchange(T a, K b) {
if (b == " EUR ") {
    return a*425;
}
else if (b == " HUF ") {
    return (a/800);
}
}

int main() {
    cout << " Convert 100 EUR to HUF : " << Exchange (100 , " EUR " ) << endl ;
    cout << " Convert 800 HUF to EUR : " << Exchange (800 , " HUF " ) << endl ;
}
