#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

// class Flight{
// protected:
//     string flightNumber;
//     string origin;
//     string destination;
//     int totalSeats;
//     int availableSeats;

// public:
//     // Constructor to initialize flight details
//     Flight(string flightNum, string org, string dest, int seats)
//         : flightNumber(flightNum), origin(org), destination(dest), totalSeats(seats), availableSeats(seats) {}

//     // Constructor for loading from file
//     Flight() {}

//     // Save flight details to a file
//     void saveToFile(ofstream &file) const
//     {
//         file << flightNumber << " " << origin << " " << destination << " "
//              << totalSeats << " " << availableSeats << endl;
//     }

//     // Load flight details from a file
//     void loadFromFile(ifstream &file)
//     {
//         file >> flightNumber >> origin >> destination >> totalSeats >> availableSeats;
//     }

//     // Display flight details
//     virtual void displayFlightDetails() const
//     {
//         cout << "Flight Number: " << flightNumber << endl;
//         cout << "Origin: " << origin << endl;
//         cout << "Destination: " << destination << endl;
//         cout << "Total Seats: " << totalSeats << endl;
//         cout << "Available Seats: " << availableSeats << endl;
//     }

//     bool bookSeat()
//     {
//         if (availableSeats > 0)
//         {
//             availableSeats--;
//             return true;
//         }
//         return false;
//     }

//      // Get available seats
//     int getAvailableSeats() const {
//         return availableSeats;
//     }

//     // Get flight number
//     string getFlightNumber() const {
//         return flightNumber;
//     }
// };

// class Passenger
// {
// private:
//     string name;
//     int age;
//     string passportNumber;

// public:
//     // Constructor
//     Passenger(string pname, int page, string ppassport)
//         : name(pname), age(page), passportNumber(ppassport) {}

//     // Constructor for loading from file
//     Passenger() {}

//     // Save passenger details to file
//     void saveToFile(ofstream &file) const
//     {
//         file << name << " " << age << " " << passportNumber << endl;
//     }

//     // Load passenger details from file
//     void loadFromFile(ifstream &file)
//     {
//         file >> name >> age >> passportNumber;
//     }

//     void displayPassengerDetails() const
//     {
//         cout << "Passenger Name: " << name << endl;
//         cout << "Age: " << age << endl;
//         cout << "Passport Number: " << passportNumber << endl;
//     }

//         string getName() const {
//         return name;
//     }

//     string getPassportNumber() const {
//         return passportNumber;
//     }

// };

// class Reservation
// {
// private:
//     Flight *flight; // Pointer to the flight object
//     Passenger passenger;

// public:
//     // Constructor
//     Reservation(Flight *f, Passenger p) : flight(f), passenger(p)
//     {
//         if (flight->bookSeat())
//         {
//             cout << "Reservation successful for " << passenger.getName() << endl;
//         }
//         else
//         {
//             cout << "Sorry, no seats available on this flight." << endl;
//         }
//     }

//     // Constructor for loading from file
//     Reservation() {}

//     // Save reservation to file
//     void saveToFile(ofstream &file) const
//     {
//         flight->saveToFile(file);   // Save flight details
//         passenger.saveToFile(file); // Save passenger details
//     }

//     // Load reservation from file
//     void loadFromFile(ifstream &file, vector<Flight> &flights)
//     {
//         Flight tempFlight;
//         tempFlight.loadFromFile(file); // Load flight from file

//         // Search for the flight in the current flight list
//         for (auto &f : flights)
//         {
//             if (f.getFlightNumber() == tempFlight.getFlightNumber())
//             {
//                 flight = &f; // Point to the existing flight object
//                 break;
//             }
//         }

//         passenger.loadFromFile(file); // Load passenger from file
//     }

//     void displayReservationDetails() const
//     {
//         cout << "Reservation Details: " << endl;
//         flight->displayFlightDetails();
//         passenger.displayPassengerDetails();
//     }
// };

// void saveReservationsToFile(const vector<Reservation> &reservations)
// {
//     ofstream file("reservations.txt");
//     if (!file.is_open())
//     {
//         cout << "Error: Could not open file for saving reservations." << endl;
//         return;
//     }
//     for (const auto &reservation : reservations)
//     {
//         reservation.saveToFile(file); // Save each reservation
//     }
//     file.close();
// }

// void loadReservationsFromFile(vector<Reservation> &reservations, vector<Flight> &flights)
// {
//     ifstream file("reservations.txt");
//     if (!file.is_open())
//     {
//         cout << "No reservation data found. Starting fresh." << endl;
//         return;
//     }

//     while (!file.eof())
//     {
//         Reservation reservation;
//         reservation.loadFromFile(file, flights); // Load reservation
//         reservations.push_back(reservation);     // Add to the list
//     }

//     file.close();
// }

// int main()
// {
//     // Flight list
//     vector<Flight> flights = {
//         Flight("AA101", "New York", "Los Angeles", 150),
//         Flight("BA202", "London", "Paris", 100)};

//     // Reservation list
//     vector<Reservation> reservations;

//     // Load reservations from the file
//     loadReservationsFromFile(reservations, flights);

//     // Create a passenger
//     Passenger passenger1("John Doe", 30, "P1234567");

//     // Make a new reservation for a flight
//     Reservation reservation1(&flights[0], passenger1);
//     reservations.push_back(reservation1);

//     // Display all reservations
//     for (const auto &res : reservations)
//     {
//         res.displayReservationDetails();
//         cout << "-------------------------" << endl;
//     }

//     // Save reservations to file before exiting
//     saveReservationsToFile(reservations);

//     return 0;
// }


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define a Person class (without file handling)
class Person {
public:
    char name[50];
    int age;
    double salary;

    // Constructor to initialize data
    Person(const string& pName = "", int pAge = 0, double pSalary = 0.0) {
        strcpy(name, pName.c_str());
        age = pAge;
        salary = pSalary;
    }

    // Function to display the person details
    void display() const {
        cout << "Name: " << name << "\nAge: " << age << "\nSalary: " << salary << endl;
    }

// // Write object data to a binary file
//     void writeToFile(ofstream& outFile) const {
//         // Write the name, age, and salary to the binary file
//         outFile.write(reinterpret_cast<const char*>(this), sizeof(*this));
//     }

//     // Read object data from a binary file
//     void readFromFile(ifstream& inFile) {
//         // Read the name, age, and salary from the binary file
//         inFile.read(reinterpret_cast<char*>(this), sizeof(*this));
//     }



};

// Standalone function to write Person object to binary file
void writeToFile(const Person& person, const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&person), sizeof(Person));
        outFile.close();
        cout << "Person details saved!" << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

// Standalone function to read Person object from binary file
void readFromFile(Person& person, const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&person), sizeof(Person));
        inFile.close();
        cout << "Person details loaded!" << endl;
    } else {
        cout << "Error opening file for reading!" << endl;
    }
}

int main() {
    // Create and save a Person object
    Person person1("John Doe", 30, 50000.0);
    writeToFile(person1, "person.dat");

    // Create an empty Person object and load the data from file
    Person person2;
    readFromFile(person2, "person.dat");

    // Display the loaded details
    person2.display();

    return 0;
}
