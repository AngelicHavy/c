#include <iostream>
using namespace std;

int main(void) {
    int input = 1;
    cin >> input;

  switch (input)
  {
  case 1:
    cout << "Kyiv - Kharkiv";
    break;
  case 2:
    cout << "Lviv - Kyiv";
    break;
  case 3:
    cout << "Kyiv - Oslo";
    break;
  case 4:
    cout << "Kyiv - Istambul";
    break;
  case 5:
    cout << "Lviv - Odesa";
    break;
  case 6:
    cout << "Odesa - Lviv";
    break;
  case 7:
    cout << "Kyiv - Mariupol";
    break;
  }
}
