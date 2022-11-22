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
        int parnRyadki = 0, parnStovp = 0;
        for (int j = 0; j < 5; j++)
        {
            if (arr[j][i] % 2 == 0)
            {
                parnStovp++;
            }
        }
        cout << "V " << i << " stovpciku " << parnStovp << " parnih chisel" << endl;
    }
}
