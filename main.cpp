#include <iostream>
#include "Fraction.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Fraction a(18, 5);
    Fraction b(36, 11);
    if(a==b) cout << "ha";
    cout << (a-b).getvalue() << endl;
    cout << a.getvalue()-b.getvalue() << endl;
    return 0;
}
