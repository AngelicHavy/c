#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    double a, b, h;
    cout << "input a" << endl;
    cin >> a;
    cout << "input b" << endl;
    cin >> b;
    cout << "input h" << endl;
    cin >> h;

    cout << endl << "-------" << endl << ":X :Y :" << endl << "-------";

    double x, y;
    while (a < b) {
        x = a;
        y = sqrt(sin(x)) + pow(x, 2);
        if (sin(x) < 0) { cout << endl <<"error. x not in ODZ"; break; }
        cout << endl << ":" << x << " :" << y << " :" << endl << "-------";
        a += h;
    }
}
