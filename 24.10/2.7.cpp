#include <iostream>
using namespace std;

int main(void) {
    double pi4 = 0.;
    long n;
    double a = 1, b = 1;

    cout << "Number of iterations? ";
    cin >> n;

    for (long i = 0; i < n; i++)
    {
        pi4 += b * (1 / a);
        a += 2;
        b *= -1;
    }

    cout.precision(20);
    cout << "Pi = " << (pi4 * 4.) << endl;
    return 0;
}
