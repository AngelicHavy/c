#include <iostream>
using namespace std;

int main(void) {
    unsigned long long result = 2;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        result *= 2;
    }
    cout << result;
}
