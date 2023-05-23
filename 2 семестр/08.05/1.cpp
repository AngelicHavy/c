//1
#include <iostream>
#include <string.h>
using namespace std;

class Tree{
public:
  void TreeBase(void){
    cout << " /\\ " << endl;
  }
};

class FTree : public Tree{
  public:
    void printFTree(){
      TreeBase();
      cout << "//\\\\" << endl;
    }
};

class STree : public Tree{
  public:
    void printSTree(){
      TreeBase();
      cout << "/**\\" << endl;
    }
};

class ThTree : public Tree{
  public:
    void printThTree(){
      TreeBase();
      cout << "/++\\" << endl;
    }
};

int main() {
  FTree spruce;
  STree Oak;
  ThTree Birch;
  for(int i = 0; i < 3; i++){
    cout << "Drawing " << i+1 << ":" << endl;
    switch(i){
      case 0:{
        spruce.printFTree();
        break;
      }
      case 1:{
        Oak.printSTree();
        break;
      }
      case 2:{
        Birch.printThTree();
        break;
      }
    }
  }
    
}

//2
#include <iostream>
#include <string.h>
using namespace std;

class IPAddress{
  protected:
    string IPaddress;
  public:
    void print(){
      cout << IPaddress << endl;
    }
};

class IPAddressChecked : public IPAddress{
  private:
    string IPAddress;
    string Check = "Correct";
  public:
    IPAddressChecked(string);
    void printChecked(){
      cout << IPaddress << " - " << this -> Check << endl;
    }
    void check(string){
      if(IPaddress > "255.255.255.255" || IPaddress < "0.0.0.0"){
        Check = "Not Correct";
      }else{
        Check = "Correct";
      }
    }
    void print(){
      IPAddress::print();
    }
};

IPAddressChecked::IPAddressChecked(string ip){
  IPAddress::IPaddress = ip;
  check(ip);
}

int main() {
  string IPaddress;
  while(1){
    cout << "Enter IP address: ";
    cin >> IPaddress;
    IPAddressChecked ipCh(IPaddress);
    cout << "Entered ip address: ";
    ipCh.print();
    cout << "Result: ";
    ipCh.printChecked();
  }
}