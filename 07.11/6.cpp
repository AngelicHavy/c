#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void) {
    int arr[12] = {2, 0, 6, -4, -3, 0, 7, 12, 11, 0, 3, -8};
    printArray(arr, 12);
    bool nul = false;

    for (int i = 0; i < 12; i++)
    {
        if (arr[i] == 0) { cout << i+1; nul = true; break; }
    }

    if (!nul) {
        cout << "there is no one 0" << endl;
    }
}
