#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    const int n = 5;
    int arr[n][n];
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = rand() % 10;

    cout << "Масив: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "Головна діагональ: ";
    for (int i = 0; i < n; i++)
        cout << arr[i][i] << " ";
    cout << endl;

    cout << "Побічна діагональ: ";
    for (int i = 0; i < n; i++)
        cout << arr[i][n - i - 1] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] % 2 == 0)
                even++;
            else
                odd++;

    cout << "Кількість парних елементів масиву: " << even << endl;
    cout << "Кількість непарних елементів масиву: " << odd << endl;

    return 0;
}