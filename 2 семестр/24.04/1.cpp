//1
#include <iostream>
#include <cmath>
using namespace std;

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
  void reserveSeats(int ticket);
  void cancelReservations(int number);
  bool isValidOperation();
  int calculatePercentage();

private:
  int id;
  int capacity;
  int reserved;
  void set(int id, int capacity, int reserved);
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
  set(id, capacity, reserved);
}

void FlightBooking::set(int id, int capacity, int reserved) {
  this->id = id;
  this->capacity = capacity;
  this->reserved = reserved;
}

int FlightBooking::calculatePercentage() {
  return (reserved * 100) / capacity;
}

void FlightBooking::printStatus() {
  cout << "Flight " << id << ": " << reserved << "/" << capacity << " (" << calculatePercentage() << "%) seats reserved" << endl;
}

void FlightBooking::reserveSeats(int ticket) {
  int newReserved = reserved + ticket;
  if (newReserved > capacity || newReserved < 0) {
    cout << "---Cannot perform this operation---" << endl;
    return;
  }

  reserved = newReserved;
}

void FlightBooking::cancelReservations(int number) {
  int newReserved = reserved - number;
  if (newReserved < 0) {
    cout << "---Cannot perform this operation---" << endl;
    return;
  }

  reserved = newReserved;
}

bool FlightBooking::isValidOperation() {
  if (capacity < 0 || reserved < 0 || reserved > capacity) {
    cout << "---Cannot perform this operation---" << endl;
    return false;
  }
  return true;
}

int main() {
  int capacity, reserved, argument;
  string command;

  cout << "Provide flight capacity: ";
  cin >> capacity;

  cout << "Provide number of reserved seats: ";
  cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  if (!booking.isValidOperation()) {
    return 1;
  }

  while (command != "quit") {
    booking.printStatus();
    cout << "What would you like to do?: ";
    getline(cin >> ws, command);

    if (command[0] == 'a') {
      argument = stoi(command.substr(4));
      booking.reserveSeats(argument);
    } else if (command[0] == 'c') {
      argument = stoi(command.substr(7));
      booking.cancelReservations(argument);
    }
  }

  return 0;
}

//2
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  FlightBooking();
  void printStatus();
  void reserveSeats(int ticket);
  void cancelReservations(int number);
  bool isFull();
  bool isValid();
  int calculatePercentage();
  void createFlight(int id, int capacity);
  void deleteFlight();
  int getID();

private:
  int id;
  int capacity;
  int reserved;
  void set(int id, int capacity, int reserved);
};

FlightBooking::FlightBooking() {
  id = 0;
  capacity = 0;
  reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
  set(id, capacity, reserved);
}

void FlightBooking::createFlight(int id, int capacity) {
  set(id, capacity, 0);
}

void FlightBooking::deleteFlight() {
  set(0, 0, 0);
}

void FlightBooking::set(int id, int capacity, int reserved) {
  this->id = id;
  this->capacity = capacity;
  this->reserved = reserved;
}

int FlightBooking::calculatePercentage() {
  return (reserved * 100) / capacity;
}

void FlightBooking::printStatus() {
  cout << "Flight " << id << ": " << reserved << "/" << capacity << " (" << calculatePercentage() << "%) seats reserved" << endl;
}

void FlightBooking::reserveSeats(int ticket) {
  int newReserved = reserved + ticket;
  if (isValid()) {
    if (!isFull() && newReserved >= 0) {
      reserved = newReserved;
      cout << "Reservation successful." << endl;
      return;
    }
    cout << "Cannot perform this operation. Reservation would exceed capacity." << endl;
    return;
  }
  cout << "Cannot perform this operation. Invalid flight." << endl;
}

void FlightBooking::cancelReservations(int number) {
  int newReserved = reserved - number;
  if (isValid()) {
    if (newReserved >= 0) {
      reserved = newReserved;
      cout << "Cancellation successful." << endl;
      return;
    }
    cout << "Cannot perform this operation. Invalid number of reservations to cancel." << endl;
    return;
  }
  cout << "Cannot perform this operation. Invalid flight." << endl;
}

bool FlightBooking::isFull() {
  return reserved == capacity;
}

bool FlightBooking::isValid() {
  return id >= 1 && capacity >= 0 && reserved >= 0;
}

int FlightBooking::getID() {
  return id;
}

int main() {
  int reserved;
  int capacity;
  int idArgument;
  int number;
  int flightIndex;
  string temp;
  string command = "";

  FlightBooking booking[10];
  booking[0] = FlightBooking(1, 400, 0);

  while (command != "quit") {
    cout << "What would you like to do?: ";
    getline(cin, command);

    if (command.substr(0, 2) == "cr") {
      int j = 0;
      int argument = 0;
      int idIndex = command.find_last_of(' ') + 1;
      for (int i = command.length() - 1; i > idIndex; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        argument += number * pow(10, j);
      }
      int capacityIndex = command.find_last_of(' ', idIndex - 2) + 1;
      j = 0;
      int idArgument = 0;
      for (int i = idIndex - 2; i > capacityIndex; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        idArgument += number * pow(10, j);
      }
      for (int i = 0; i < 10; i++) {
        if (booking[i].getID() == 0) {
          if (idArgument >= 1) {
            if (argument >= 0) {
              booking[i].createFlight(idArgument, argument);
              cout << "Flight with ID " << idArgument << " and capacity " << argument << " created." << endl;
              break;
            }
          } else {
            cout << "Incorrect ID." << endl;
            break;
          }
        }
        if (i == 9) {
          cout << "Maximum number of flights reached." << endl;
        }
      }
    } else if (command[0] == 'd') {
      int idIndex = command.find_last_of(' ') + 1;
      int idArgument = stoi(command.substr(idIndex));
      for (int i = 0; i < 10; i++) {
        if (idArgument == booking[i].getID()) {
          if (booking[i].isValid()) {
            booking[i].deleteFlight();
            cout << "Flight with ID " << idArgument << " deleted." << endl;
          } else {
            cout << "Cannot perform this operation. Invalid flight." << endl;
          }
          break;
        }
        if (i == 9) {
          cout << "No flight with ID " << idArgument << " found." << endl;
        }
      }
    } else if (command[0] == 'l') {
      cout << "List of Flights:" << endl;
      for (int i = 0; i < 10; i++) {
        if (booking[i].getID() != 0) {
          booking[i].printStatus();
        }
      }
    } else if (command[0] == 'a') {
      int j = 0;
      int argument = 0;
      int idIndex = command.find_last_of(' ') + 1;
      for (int i = command.length() - 1; i > idIndex; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        argument += number * pow(10, j);
      }
      int capacityIndex = command.find_last_of(' ', idIndex - 2) + 1;
      j = 0;
      int idArgument = 0;
      for (int i = idIndex - 2; i > capacityIndex; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        idArgument += number * pow(10, j);
      }
      for (int i = 0; i < 10; i++) {
        if (idArgument == booking[i].getID()) {
          booking[i].reserveSeats(argument);
          break;
        }
        if (i == 10) {
          cout << "No flight with ID " << idArgument << " found." << endl;
        }
      }
    } else if (command.substr(0, 2) == "ca") {
      int j = 0;
      int argument = 0;
      int idIndex = command.find_last_of(' ') + 1;
      for (int i = command.length() - 1; i > idIndex; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        argument += number * pow(10, j);
      }
      int capacityIndex = command.find_last_of(' ', idIndex - 2) + 1;
      j = 0;
      int idArgument = 0;
      for (int i = idIndex - 2; i > capacityIndex; i--, j++) {
        temp = command[i];
        number = stoi(temp);
        idArgument += number * pow(10, j);
      }
      for (int i = 0; i < 10; i++) {
        if (idArgument == booking[i].getID()) {
          booking[i].cancelReservations(argument);
          break;
        }
        if (i == 9) {
          cout << "No flight with ID " << idArgument << " found." << endl;
        }
      }
    }
  }
  return 0;
}



