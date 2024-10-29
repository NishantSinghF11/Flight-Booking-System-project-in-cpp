# Flight Reservation System
This is a C++ project that implements a simple Flight Reservation/Booking System. The system allows users to book flights, view flight details, check availability, cancel bookings, view My bookings and manage flight schedules. It can be used by both administrators (to manage the flight system) and passengers (to book and manage their reservations).
This project has 2040+ line's code in main file📂. 

# Usage
Upon running the system, the user can choose whether to log in as a Passenger or Admin.

# Features
### User Features 
- Flight Booking : Users can search for available flights and book seats.
- View Booking Details : Users can view the details of their flight bookings.
- Cancel Bookings : Users can cancel their reservations if needed.
- View Available Flights : Users can check all available flights based on specific criteria (e.g., date, destination).
- View Detail's : user can view All details of Airline's  (e.g., Helpline no., General details, etc.)
- flight Announcement : Users can see their details and view their flight Announcement's.
### Admin Features 
- Add New Flights : Admins can add new flights with details like flight number, destination, date, time, filght Fare and available seats, etc...
- View All Flights : Admin can views all Flight's its Available.
- View All Bookings : Admins can view all reservations made by passengers.
- Update or Remove Flights: Admins can modify flight details or remove flights that are no longer available.
- Manage Flight Schedules: Admins can update flight schedules, including delays and cancellations.
- Add Flight Announcement : Admins can Add reports/Announcement of all flight bookings and reservations.
### Technologies Used 
- C++
- File Handling : The project uses file handling to store and retrieve flight and booking details.
- Object-Oriented Programming (OOP) : principles like classes and inheritance are used to model the system.

# Project Structure
```
Flight-Reservation-System/
│                            (.dat files are binary files formats)
├── README.md                 # This file is takes all details of this projects first read this file
├── main.cpp                  # The main entry point of the project
├── Flight.dat                # This File is the binary file can store All flight Details 
├── passenger.dat             # This file can store all passenger details
├── reservation.dat           # This file can store Reservation's details with all passengers in vectors forms  
├── admin_login_detail.txt    # Admin login details username and passwords file
├── login_detail.txt          # user details (username, passwords, name, mob no., etc.)
├── flight_announcement.txt   # Flight announcement file take 📢 announcement of the flight or airline's 
└── AnimationFiles/
    ├── a1.txt, a2.txt,.....  # This files can store all animations files in the text form
    └── welcometext.txt       # This is first welcome file 
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
# Contributing
  If you'd like to contribute to this project, please fork the repository and create a pull request with your changes.

# Thank you 

  
