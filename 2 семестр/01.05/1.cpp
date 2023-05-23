#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class GMMS {
public:
  GMMS();
  GMMS(int, string, int);
  void createMember(int);
  void deleteMember();
  void extendMembership(int);
  void cancelSubscription();
  int getID();
  void print(int);
  string name;
  int nameLength;

private:
  int id;
  int subscription;
  void set(int, string, int);
  void get();
};

GMMS::GMMS() {
  this->id = 0;
  this->name = "";
  this->subscription = 0;
}

GMMS::GMMS(int ID, string Name, int Month) {
  set(ID, Name, Month);
}

void GMMS::createMember(int ID) {
  this->id = ID;
}

void GMMS::deleteMember() {
  this->id = 0;
  this->nameLength = 0;
}

void GMMS::extendMembership(int Month) {
  this->subscription += Month;
}

void GMMS::cancelSubscription() {
  this->subscription = 0;
}

void GMMS::print(int nameLength) {
  cout << "Member " << this->id << ": ";
  for (int i = 0; i < nameLength; i++) {
    cout << this->name[i];
  }
  cout << ", subscription valid for " << this->subscription << " month(s)" << endl;
}

void GMMS::set(int ID, string Name, int Month) {
  this->id = ID;
  this->name = Name;
  this->subscription = Month;
}

int GMMS::getID() {
  return this->id;
}

int main() {
  string command = "";
  int argument = 0;
  int IDArgument = 0;
  string NameArgument = "";
  int j, i;
  int number;
  string temp;
  int temp2;

  GMMS subscription[4];
  subscription[0] = GMMS(1, "John Doe", 6);
  subscription[0].nameLength = 8;

  while (command != "quit") {
    i = 0;
    j = 0;
    argument = 0;
    IDArgument = 0;
    NameArgument = "";

    cout << "What would you like to do?: ";
    getline(cin, command);

    if (command[0] == 'c' && command[1] == 'r') {
      for (i = command.length() - 1; j < 2; i--) {
        if (command[i] == ' ') {
          j++;
        }
      }
      temp2 = i--;
      for (i += 3, j = 0; i < command.length(); i++, j++) {
        NameArgument[j] = command[i];
      }
      temp2 = j;
      for (i = temp2, j = 0; command[i] != ' '; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        IDArgument += number * pow(10, j);
      }
      for (i = 0; i < 4; i++) {
        if (subscription[i].getID() == 0) {
          if (IDArgument >= 1) {
            subscription[i].nameLength = temp2;
            for (j = 0; j < temp2; j++) {
              subscription[i].name[j] = NameArgument[j];
            }
            subscription[i].createMember(IDArgument);
            break;
          } else {
            cout << "-----------------------" << endl;
            cout << "--- Incorrect ID ---" << endl;
            cout << "-----------------------" << endl;
            break;
          }
        }
        if (i == 3) {
          cout << "-----------------------" << endl;
          cout << "--- Maximum member number ---" << endl;
          cout << "-----------------------" << endl;
        }
      }
    } else if (command[0] == 'l') {
      cout << "-----------------------" << endl << "List: " << endl << "-----------------------" << endl;
      for (i = 0; i < 4; i++) {
        temp2 = subscription[i].nameLength;
        if (subscription[i].getID() != 0) {
          subscription[i].print(temp2);
        }
      }
      cout << "-----------------------" << endl;

    } else if (command[0] == 'd') {
      for (i = command.length() - 1; command[i] != ' '; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        IDArgument += number * pow(10, j);
      }
      for (i = 0; i < 4; i++) {
        if (IDArgument == subscription[i].getID()) {
          subscription[i].deleteMember();
          break;
        }
        if (i == 3) {
          cout << "-----------------------" << endl;
          cout << "--- No member with ID " << IDArgument << " ---" << endl;
          cout << "-----------------------" << endl;
        }
      }
    } else if (command[0] == 'e') {
      for (i = command.length() - 1; command[i] != ' '; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        argument += number * pow(10, j);
      }
      for (i--, j = 0; command[i] != ' '; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        IDArgument += number * pow(10, j);
      }
      for (i = 0; i < 4; i++) {
        if (IDArgument == subscription[i].getID()) {
          subscription[i].extendMembership(argument);
          break;
        }
        if (i == 3) {
          cout << "-----------------------" << endl;
          cout << "--- No member with ID " << IDArgument << " ---" << endl;
          cout << "-----------------------" << endl;
        }
      }
    } else if (command[0] == 'c' && command[1] == 'a') {
      for (i = command.length() - 1; command[i] != ' '; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        IDArgument += number * pow(10, j);
      }
      for (i = 0; i < 4; i++) {
        if (IDArgument == subscription[i].getID()) {
          subscription[i].cancelSubscription();
          break;
        }
        if (i == 3) {
          cout << "-----------------------" << endl;
          cout << "--- No member with ID " << IDArgument << " ---" << endl;
          cout << "-----------------------" << endl;
        }
      }
    }
  }

  return 0;
}

//2
#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;

class Fraction{
  public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
    double Double;
    void set(int, int);
  private:
    int numerator;
    int denominator;
    
    string String;
};
Fraction::Fraction(int numerator, int denominator){
  set(numerator, denominator);
}
string Fraction::toString(){
  Fraction::toDouble();
  int i = 0;
  if(this -> denominator < 0){
    this -> denominator *= (-1);
    this -> numerator *= (-1);
  }
  if(this -> numerator % this -> denominator == 0){
    this -> String = to_string(this -> numerator / this -> denominator);
    return String;
  }
  if(abs(this -> numerator) > this -> denominator){
    for(i = 0; abs(this -> numerator) > this -> denominator; i++){
      if(this -> numerator > 0){
        this -> numerator -= denominator;
      }else if(this -> numerator < 0){
        this -> numerator += denominator;
      }
    }
  }
    if(this -> numerator < 0){
      i *= (-1);
    }
  if(i == 0){
    this -> String = to_string(this -> numerator) + "/" + to_string(this -> denominator);
  }else if(this -> numerator <0){
    this -> numerator = abs(this -> numerator);
  this -> String = to_string(i) + " " + to_string(this -> numerator) + "/" + to_string(this -> denominator);
  }else{
  this -> String = to_string(i) + " " + to_string(this -> numerator) + "/" + to_string(this -> denominator);
  }
  return String;
}
void Fraction::set(int numerator, int denominator){
  this -> numerator = numerator;
  this -> denominator = denominator;
}

double Fraction::toDouble(){
  setprecision(2);
  this -> Double = (double) this -> numerator / (double) this -> denominator;
  return this -> Double;
}

int main(void) {
  int num, den, Itemp, i, j;
  string Stemp;
  double Dtemp;
  string input = "";
  Fraction fraction(num, den);
  
  while (true) {
    cout << "Input: ";
    getline(cin, input);
    for (i = input.length() - 1, j = 0, num = 0, den = 0; input[i] != '/'; i--, j++) {
      Stemp = input[i];
      if(Stemp != "-"){
        num = stoi(Stemp);
        den += num * pow(10, j);
      }else{
        den *= (-1);
      }
      }
    for (i--, j = 0, num = 0; i >= 0; i--, j++) {
      Stemp = input[i];
      if(Stemp != "-"){
        Itemp = stoi(Stemp);
        num += Itemp * pow(10, j);
      }else{
        den *= (-1);
      }
    }
    fraction.set(num, den);
   Dtemp = fraction.toDouble();
    cout << fraction.toString() << " is " << Dtemp << " in decimal" << endl;
  } 
  
  return 0;
}
