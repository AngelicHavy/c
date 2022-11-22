#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double array[5];
    double input;

    for (int i = 0; i < 5; i++)
    {
        cin >> input;
        array[i] = input;
    }

    for ( int x : array)
    {
        cout << endl <<  pow(sin(x), 5) + abs(5 * x - 1.5);
    }
}
