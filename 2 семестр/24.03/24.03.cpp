//1
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for(int i = 2; i<=21; i++){
      if(isPrime(i)){
        cout << i << " is a prime number" << endl;
      }else{
        cout << i << " is not a prime number" << endl;
      }
    }
    return 0;
}

//2

#include <iostream>
using namespace std;

int increment(int x) {
    cout << ++x;
    return x;
}

int increment(int x, int i) {
    return x + i;
}

int main() {
    int var = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            var = increment(var);
        } else {
            var = increment(var, i);
        }
    }
    cout << var << endl;
    return 0;
}

