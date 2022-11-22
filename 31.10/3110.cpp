//1
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
    int arr[12] = {2, -5, 6, -4, -3, 4, 7, 12, 11, -1, 3, -8};
    printArray(arr, 12);
    int maxId = 0;

    for (int i = 0; i < 12; i++)
    {
        if (arr[i] > arr[maxId]) maxId = i;
    }

    for (int j = 0; j < maxId; j++)
    {
        if (arr[j] < 0) arr[j] = 0;
    }

    printArray(arr, 12);
}

//2
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
    int arr[12] = {2, -5, 6, -4, -3, 4, 7, 12, 11, -1, 3, -8};
    printArray(arr, 12);
    int maxId = 0;

    for (int i = 0; i < 12; i++)
    {
        if (arr[i] > arr[maxId]) maxId = i;
    }

    for (int j = 0; j < maxId; j++)
    {
        if (arr[j] < 0) arr[j] = 0;
    }

    printArray(arr, 12);
}
