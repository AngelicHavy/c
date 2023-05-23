//1
#include <iostream>
#include <string>
using namespace std;

class ShopItemOrder {
private:
string name;
double price;
int numberOfItems;

public:
ShopItemOrder(string name, double price, int numberOfItems);
void print();
double getTotalPrice();
};

ShopItemOrder::ShopItemOrder(string name, double price, int numberOfItems) {
set(name, price, numberOfItems);
}

void ShopItemOrder::set(string name, double price, int numberOfItems) {
this->name = name;
this->price = price;
this->numberOfItems = numberOfItems;
}

void ShopItemOrder::print() {
cout << name << "/" << price << "/" << numberOfItems;
}

double ShopItemOrder::getTotalPrice() {
return price * numberOfItems;
}

int main() {
ShopItemOrder item1("computer", 10000, 2);
item1.print();
return 0;
}
//2
#include <iostream>
using namespace std;

class FlightBooking {
public:
FlightBooking(int id, int capacity, int reserved);
void printStatus();

private:
int id;
int capacity;
int reserved;
int calculatePercentage();
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
this->id = id;
this->capacity = capacity;
this->reserved = reserved;
}

void FlightBooking::printStatus() {
cout << "Flight " << id << ": " << reserved << "/" << capacity << " (" << calculatePercentage() << "%) seats reserved" << endl;
}

int FlightBooking::calculatePercentage() {
return (reserved * 100) / capacity;
}

int main() {
int reserved = 0;
int capacity = 0;
cout << "Provide flight capacity: ";
cin >> capacity;
cout << "Provide number of reserved seats: ";
cin >> reserved;
FlightBooking booking(1, capacity, reserved);
booking.printStatus();
return 0;
}