#include <iostream>
using namespace std;

int main(void) {
    int input, a1, a2, a3, output = 0;
    cin >> input;

    // Розкладання трьозначого заданого числа на цифри
    a1 = input % 10;
    input /= 10;
    a2 = input % 10;
    input /= 10;
    a3 = input % 10;

    if (a1 > 5) { output += a1; }
    if (a2 > 5) { output += a2; }
    if (a3 > 5) { output += a3; }

    cout << output;
}
