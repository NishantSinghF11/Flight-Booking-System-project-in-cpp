#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Flight {
protected:
    string flightNumber;
    string origin;
    string destination;
    int totalSeats;
    int availableSeats;

public:
    // Constructor to initialize flight details
    Flight(string flightNum, string org, string dest, int seats)
        : flightNumber(flightNum), origin(org), destination(dest), totalSeats(seats), availableSeats(seats) {}

    // Default constructor for file loading
    Flight() {}

    // Save flight details to a binary file
    void saveToFile(ofstream &file) const {
        size_t length;

        // Save flightNumber
        length = flightNumber.size();
        file.write(reinterpret_cast<const char*>(&length), sizeof(length));
        file.write(flightNumber.c_str(), length);

        // Save origin
        length = origin.size();
        file.write(reinterpret_cast<const char*>(&length), sizeof(length));
        file.write(origin.c_str(), length);

        // Save destination
        length = destination.size();
        file.write(reinterpret_cast<const char*>(&length), sizeof(length));
        file.write(destination.c_str(), length);

        // Save seats data
        file.write(reinterpret_cast<const char*>(&totalSeats), sizeof(totalSeats));
        file.write(reinterpret_cast<const char*>(&availableSeats), sizeof(availableSeats));
    }

    // Load flight details from a binary file
    void loadFromFile(ifstream &file) {
        size_t length;

        // Load flightNumber
        file.read(reinterpret_cast<char*>(&length), sizeof(length));
        flightNumber.resize(length);
        file.read(&flightNumber[0], length);

        // Load origin
        file.read(reinterpret_cast<char*>(&length), sizeof(length));
        origin.resize(length);
        file.read(&origin[0], length);

        // Load destination
        file.read(reinterpret_cast<char*>(&length), sizeof(length));
        destination.resize(length);
        file.read(&destination[0], length);

        // Load seats data
        file.read(reinterpret_cast<char*>(&totalSeats), sizeof(totalSeats));
        file.read(reinterpret_cast<char*>(&availableSeats), sizeof(availableSeats));
    }

    // Display flight details
    void displayFlightDetails() const {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Origin: " << origin << endl;
        cout << "Destination: " << destination << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }

    bool bookSeat() {
        if (availableSeats > 0) {
            availableSeats--;
            return true;
        }
        return false;
    }

    string getFlightNumber() const { return flightNumber; }
    int getAvailableSeats() const { return availableSeats; }
};


class Passenger {
private:
    string name;
    int age;
    string passportNumber;

public:
    // Constructor to initialize passenger details
    Passenger(string pname, int page, string ppassport)
        : name(pname), age(page), passportNumber(ppassport) {}

    // Default constructor for file loading
    Passenger() {}

    // Save passenger details to binary file
    void saveToFile(ofstream &file) const {
        size_t length;

        // Save name
        length = name.size();
        file.write(reinterpret_cast<const char*>(&length), sizeof(length));
        file.write(name.c_str(), length);

        // Save age
        file.write(reinterpret_cast<const char*>(&age), sizeof(age));

        // Save passportNumber
        length = passportNumber.size();
        file.write(reinterpret_cast<const char*>(&length), sizeof(length));
        file.write(passportNumber.c_str(), length);
    }

    // Load passenger details from binary file
    void loadFromFile(ifstream &file) {
        size_t length;

        // Load name
        file.read(reinterpret_cast<char*>(&length), sizeof(length));
        name.resize(length);
        file.read(&name[0], length);

        // Load age
        file.read(reinterpret_cast<char*>(&age), sizeof(age));

        // Load passportNumber
        file.read(reinterpret_cast<char*>(&length), sizeof(length));
        passportNumber.resize(length);
        file.read(&passportNumber[0], length);
    }

    void displayPassengerDetails() const {
        cout << "Passenger Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Passport Number: " << passportNumber << endl;
    }
};


class Reservation {
private:
    Flight* flight;
    Passenger passenger;

public:
    // Constructor to create a new reservation
    Reservation(Flight* f, Passenger p) : flight(f), passenger(p) {
        if(flight->bookSeat()) {
            cout << "Reservation successful!" << endl;
        } else {
            cout << "No seats available!" << endl;
        }
    }

    // Default constructor for file loading
    Reservation() : flight(nullptr) {}

    // Save reservation to binary file
    void saveToFile(ofstream &file) const {
        flight->saveToFile(file);  // Save flight details
        passenger.saveToFile(file);  // Save passenger details
    }

    // Load reservation from binary file
    void loadFromFile(ifstream &file, vector<Flight> &flights) {
        Flight tempFlight;
        tempFlight.loadFromFile(file);  // Load flight data

        // Match the loaded flight with an existing flight object
        for (auto &f : flights) {
            if (f.getFlightNumber() == tempFlight.getFlightNumber()) {
                flight = &f;  // Link to existing flight object
                break;
            }
        }

        // Load passenger data
        passenger.loadFromFile(file);
    }

    // Display reservation details
    void displayReservationDetails() const {
        cout << "Reservation Details:" << endl;
        flight->displayFlightDetails();
        passenger.displayPassengerDetails();
    }
};


void saveReservationsToBinaryFile(const vector<Reservation> &reservations) {
    ofstream file("reservations.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Could not open file for saving reservations." << endl;
        return;
    }

    for (const auto &reservation : reservations) {
        reservation.saveToFile(file);  // Save each reservation
    }

    file.close();
}


void loadReservationsFromBinaryFile(vector<Reservation> &reservations, vector<Flight> &flights) {
    ifstream file("reservations.bin", ios::binary);
    if (!file.is_open()) {
        cout << "No reservation data found. Starting fresh." << endl;
        return;
    }

    while (true) {
        Reservation reservation;
        reservation.loadFromFile(file, flights);  // Load reservation
        if (file.eof()) {
            break; // Exit loop if end of file is reached
        }
        reservations.push_back(reservation);  // Add to the list
    }

    file.close();
}


int main() {
    // Flight list
    vector<Flight> flights = {
        Flight("AA101", "New York", "Los Angeles", 150),
        Flight("BA202", "London", "Paris", 100)
    };

    // Reservation list
    vector<Reservation> reservations;

    // Load reservations from the binary file
    loadReservationsFromBinaryFile(reservations, flights);

    // Create a passenger
    Passenger passenger1("John Doe", 30, "P1234567");

    // Make a new reservation for a flight
    Reservation reservation1(&flights[0], passenger1);
    reservations.push_back(reservation1);

    // Display all reservations
    for (const auto &res : reservations) {
        res.displayReservationDetails();
        cout << "-------------------------" << endl;
    }

    // Save reservations to binary file before exiting
    saveReservationsToBinaryFile(reservations);

    return 0;
}
 