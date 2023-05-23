//1
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
string name;
int age;

};
void print(Person* person)
{
cout << person->name << " is " << person->age << " years old" << endl;
}

int main()
{
Person person1;
person1.name = "Harry";
person1.age = 23;
cout << "Meet " << person1.name << '\n';
print(&person1);
  
Person person2;
person2.name = "Genry";
person2.age = 48;
cout << "Meet " << person2.name << '\n';
print(&person2);

Person person3;
person3.name = "Mia";
person3.age = 29;
cout << "Meet " << person3.name << '\n';
print(&person3);

return 0;
}

//2
#include <iostream>
#include <string>
using namespace std;
class Square
{
private:
  double side;
  double area;
public:
  Square(double side);
  void set_side(double side){
    if(side < 0){
      this -> side = 0;
      this -> area = 0;
    }else{
      this -> side = side;
      this -> area = side * side;
    }
  }
void print()
{
  cout << "Square: side=" << this -> side << " area=" << this -> area << endl;
}
};
// Your code here
  Square::Square(double side)
{
  void set_side(double side);
}
  

int main()
{
Square s(4);
s.print();
s.set_side(2.0);
s.print();
s.set_side(-33.0);
s.print();
return 0;
}

//3
#include <iostream>
#include <string>
using namespace std;

class LazySquare {
public:
  void set_side(double side) {
    if(this -> side != side){
      this -> side_changed = true;
      this -> side = side;
    }else{
      side_changed = false;
    }
    
  }
  double get_area() {
    if (side_changed) {
      area = side * side;
    }
    return area;
  }

private:
  double side;
  double area;
  bool side_changed;
};

class AdHocSquare : public LazySquare{
public:
  void set_side(double side) {
    if (side < 0) {
      LazySquare::set_side(0);
      this -> side = 0;
    }else{
      LazySquare::set_side(side);
      this -> side = side;
    }
  }
  double get_area() {
    return LazySquare::get_area();
  }
  void print(double side) {
    set_side(side);
     cout << "Square: side=" << this -> side << " area=" << get_area() <<  endl;
   }

private:
  double side;
};

int main() {
  AdHocSquare s;
  s.print(2.0);
  s.print(-33.0);
  s.print(0);
  s.print(5000);
  return 0;
}
