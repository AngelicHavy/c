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

    int max = arr[0][0], min = arr[0][0], maxId = 0, minId = 0, id = 0;

    for (int i = 0; i < 5; i++)
    {
        int sumStovp = 0;
        for (int j = 0; j < 5; j++)
        {
            id++;
            if (arr[i][j] < min) { min = arr[i][j]; minId = id; }
            if (arr[i][j] > max) { max = arr[i][j]; maxId = id; }
        }
    }
    cout << "Min - " << min << " ID - " << minId << endl;
    cout << "Max - " << max << " ID - " << maxId << endl;
}
