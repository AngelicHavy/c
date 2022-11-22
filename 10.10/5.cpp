#include <iostream>
using namespace std;

int main()
{
    int a;
    int result = 1;
    cin >> a;

    while (a > 0) {
        if (a % 2 != 0) {
            result *= (a % 10);
        }
        a = a / 10;
    }
    cout << result;
}
