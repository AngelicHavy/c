//6
#include <iostream>
using namespace std;

int main(void) {
    bool answer = false;
    int value;
    cout << "Enter a value: ";
    cin >> value;
    if ((value >= 0 && value < 10)||((value * 2) < 20 && (value - 2) > -2)  ((value - 1) > 1 && (value / 2) < 10) || (value == 111)) { answer = true; } 
    cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
    return 0;
}

//7
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    float arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "input next number - ";
        cin >> arr[i];
    }
    cout << floor(arr[0]) << endl; // only integer from float
    cout << ceil(arr[1]) << endl; // round float to bigger int
    cout << round(arr[2]) << endl; // true float round 
    cout << trunc(arr[3]) << endl; // round float to less int
    cout << round(arr[4] * 100)/100 << endl; // round to 0.00
    return 0;
}
//8
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    float first, second;
    cout << "Input 1st and 2nd dividers - " << endl;
    cin >> first;
    cin >> second;
    if (1.0 / first == 1.0 / second) { cout << "Results are equal (by 0.000001 epsilon)"; }
    else { cout << "Results are not equal (by 0.000001 epsilon)"; }
    return 0;
}
//9
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int arr[4];
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
        if (arr[i] < 1 || arr[i] > 255) { return -1; }
    }
    cout << arr[0] << "." << arr[1] << "." << arr[2] << "." << arr[3];
    return 0;
}
