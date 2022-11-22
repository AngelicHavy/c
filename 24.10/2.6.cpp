#include <iostream>
using namespace std;

int main(void) {
    int c0;
    cin >> c0;
    while (c0 != 1)
    {
        if (c0 % 2 == 0) { c0 /= 2; }
        else { c0 = c0 * 3 + 1; }
        cout << c0 << endl;
    }
}
