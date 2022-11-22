#include <iostream>
using namespace std;

int main()
{
    int result = 1;
    for (int i = 1; i < 40; i++) {
        if (i % 4 == 0) {
            cout << i << endl;
            result *= i;
        }
    }
    cout << result;
}
