#include <iostream>
using namespace std;

int main(void) {
    int arr[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int rDiagId = 2, lDiagId = 0, rDiagSum = 0, lDiagSum = 0; 
    for (int j = 0; j < 3; j++)
    {
        rDiagSum += arr[rDiagId][j];
        lDiagSum += arr[lDiagId][j];

        rDiagId--;
        lDiagId++;
    }
    cout << "Summa pravoyi diagonali " << rDiagSum << endl;
    cout << "Summa livoyi diagonali " << lDiagSum << endl;
}
