//1
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
  float *array = new float [10];
  int pos=0, neg=0;
  
  srand(time(NULL));
  
  for (int i=0; i<10; i++){
    array[i] = 0.1*(rand()%40-20);
    if(array[i]>0){
      pos++;
    }else if(array[i]<0){
      neg++;
    }
    if(i<9){
    cout << array[i] << ", ";
    }else{
      cout << array[i] << "." << endl;
    }
  }
  cout << "Positive: " << pos << endl << "Negative: " << neg;
  delete [] array;
}

//2
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int even=0, odd=0;
  int **array = new int* [3];
  for (int line=0; line<3; line++){
    array[line] = new int [3];
  }

  srand(time(NULL));
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      array[i][j] = rand()%20-10;
      if(i+j<4){
        cout << array[i][j] << ", ";
      }else{
        cout << array[i][j] << ".";
      }
    }
    cout << endl;
  }

  cout << "Elements of the main diagonal: ";
  for(int i=0;i<3; i++){
    if (i<2){
    cout << array[i][i] << ", ";
    }else{
      cout << array[i][i] << "." << endl;
    }
  }

  cout << "Elements of the side diagonal: ";
  for(int i=0, j=2; i<3; i++, j--){
    if (i<2){
      cout << array[i][j] << ", ";
    }else{
      cout << array[i][j] << "." << endl;
    }
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if (array[i][j]%2==0){
        even++;
      }else{
        odd++;
      }
    }
  }
  cout << "Number of even numbers: " << even << endl;
  cout << "Number of odd numbers: " << odd << endl;
  
  for (int line=0; line<3; line++){
    delete [] array [line];
  }
}