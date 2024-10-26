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

    // Constructor for loading from file
    Flight() {}

    // Save flight details to a file
    void saveToFile(ofstream &file) const {
        file << flightNumber << " " << origin << " " << destination << " "
             << totalSeats << " " << availableSeats << endl;
    }

    // Load flight details from a file
    void loadFromFile(ifstream &file) {
        file >> flightNumber >> origin >> destination >> totalSeats >> availableSeats;
    }

    // Display flight details
    virtual void displayFlightDetails() const {
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
    // Constructor
    Passenger(string pname, int page, string ppassport)
        : name(pname), age(page), passportNumber(ppassport) {}

    // Constructor for loading from file
    Passenger() {}

    // Save passenger details to file
    void saveToFile(ofstream &file) const {
        file << name << " " << age << " " << passportNumber << endl;
    }

    // Load passenger details from file
    void loadFromFile(ifstream &file) {
        file >> name >> age >> passportNumber;
    }

    void displayPassengerDetails() const {
        cout << "Passenger Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Passport Number: " << passportNumber << endl;
    }

     string getName() const {
        return name;
    }

    string getPassportNumber() const {
        return passportNumber;
    }

};


class Reservation {
private:
    Flight* flight;  // Pointer to the flight object
    Passenger passenger;

public:
    // Constructor
    Reservation(Flight* f, Passenger p) : flight(f), passenger(p) {
        if (flight->bookSeat()) {
            cout << "Reservation successful for " << passenger.getName() << endl;
        } else {
            cout << "Sorry, no seats available on this flight." << endl;
        }
    }

    // Constructor for loading from file
    Reservation() {}

    // Save reservation to file
    void saveToFile(ofstream &file) const {
        flight->saveToFile(file);  // Save flight details
        passenger.saveToFile(file);  // Save passenger details
    }

    // Load reservation from file
    void loadFromFile(ifstream &file, vector<Flight> &flights) {
        Flight tempFlight;
        tempFlight.loadFromFile(file);  // Load flight from file

        // Search for the flight in the current flight list
        for (auto &f : flights) {
            if (f.getFlightNumber() == tempFlight.getFlightNumber()) {
                flight = &f;  // Point to the existing flight object
                break;
            }
        }

        passenger.loadFromFile(file);  // Load passenger from file
    }

    void displayReservationDetails() const {
        cout << "Reservation Details: " << endl;
        flight->displayFlightDetails();
        passenger.displayPassengerDetails();
    }
};


void saveReservationsToFile(const vector<Reservation> &reservations) {
    ofstream file("reservations.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open file for saving reservations." << endl;
        return;
    }
    for (const auto &reservation : reservations) {
        reservation.saveToFile(file);  // Save each reservation
    }
    file.close();
}


void loadReservationsFromFile(vector<Reservation> &reservations, vector<Flight> &flights) {
    ifstream file("reservations.txt");
    if (!file.is_open()) {
        cout << "No reservation data found. Starting fresh." << endl;
        return;
    }

    while (!file.eof()) {
        Reservation reservation;
        reservation.loadFromFile(file, flights);  // Load reservation
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

    // Load reservations from the file
    loadReservationsFromFile(reservations, flights);

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

    // Save reservations to file before exiting
    saveReservationsToFile(reservations);

    return 0;
}

