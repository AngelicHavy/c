#include <iostream>
using namespace std;

int main(void) {
    int arr[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) 
        {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        int sumRyadki = 0;
        for (int j = 0; j < 5; j++)
        {
            sumRyadki += arr[i][j];
        }
        cout << "V " << i << " ryadku - " << sumRyadki << endl;
    }
}
