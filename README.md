# Flight Reservation System
This is a C++ project that implements a simple Flight Reservation System. The system allows users to book flights, view flight details, check availability, cancel bookings, and manage flight schedules. It can be used by both administrators (to manage the flight system) and passengers (to book and manage their reservations).

# Features
### User Features 
- Flight Booking : Users can search for available flights and book seats.
- View Booking Details : Users can view the details of their flight bookings.
- Cancel Bookings : Users can cancel their reservations if needed.
- View Available Flights : Users can check all available flights based on specific criteria (e.g., date, destination).
- Passenger Information : Users can update their details and view their booking history.
### Admin Features 
- Add New Flights : Admins can add new flights with details like flight number, destination, date, time, and available seats.
- View All Bookings : Admins can view all reservations made by passengers.
- Update or Remove Flights: Admins can modify flight details or remove flights that are no longer available.
- Manage Flight Schedules: Admins can update flight schedules, including delays and cancellations.
- Generate Flight Reports: Admins can generate reports of all flight bookings and reservations.
### Technologies Used 
- C++
- File Handling : The project uses file handling to store and retrieve flight and booking details.
- Object-Oriented Programming (OOP) : principles like classes and inheritance are used to model the system.

# Project Structure
```
Flight-Reservation-System/
│
├── main.cpp          # The main entry point of the project
├── Flight.h          # Flight class header file
├── Flight.cpp        # Flight class implementation
├── Passenger.h       # Passenger class header file
├── Passenger.cpp     # Passenger class implementation
├── Admin.h           # Admin class header file
├── Admin.cpp         # Admin class implementation
├── Booking.h         # Booking class header file
├── Booking.cpp       # Booking class implementation
├── README.md         # This file
└── data/
    ├── flights.txt    # File to store flight details
    └── bookings.txt   # File to store passenger bookings
```

# Installation
**1 . Create environment :**
```
git init
```
**2 . Clone the repository :**
```
git clone https://github.com/NishantSingh825/Flight-Booking-System-project-in-cpp.git
```
**3. Navigate to the project directory :**
```
cd flight-reservation-system
```
# Usage
Upon running the system, the user can choose whether to log in as a Passenger or Admin.

### **For Passengers :**
- Book Flight: Enter your details, select the flight, and confirm the booking.
- View Flights: Browse all available flights based on your preferences.
- Cancel Flight: Enter your booking ID and cancel your flight if necessary.
### **For Admins:**
- Add New Flight: Add new flight information (flight number, destination, time, seats available).
- View Bookings: Check all the current reservations and manage passengers.
- Manage Flights: Update flight schedules, cancel flights, or modify flight information.
- Generate Reports: Generate booking reports for business analysis.

# Contributing
  If you'd like to contribute to this project, please fork the repository and create a pull request with your changes.

# Thank you 
  
