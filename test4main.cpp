#include <iostream> 
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <windows.h>
using namespace std; 

bool login_status = false;
bool signup_ok = false;
string login_user;
bool admin_login_status = false;
string administrator_user;

void main_menu(); //declear kar hai function
void login_menu();//declear kar hai function

class Flight{
    protected:
    string flight_number;
    string flight_name;
    string departure_time;
    string source;
    string destination;
    int totalSeats;
    int availableSeats;
    float flight_price;
    // vector<string> source;
    // vector<string> destination;

    public:
    Flight(){}
    Flight(string f_num, string f_name, string time, string src, string des , int seats, float price){
        flight_number = f_num;
        flight_name = f_name;
        departure_time = time;
        totalSeats = seats;
        availableSeats = seats;
        flight_price = price;
        source = src;
        destination = des;
        // source.push_back(src);
        // destination.push_back(des);
    } 

    void add_source(string src){
        // source.push_back(ori);
            source = src;
    }

    void add_destination(string des){
        // destination.push_back(des);
        destination = des;
    }

    void update_departure_time(string t){
        departure_time = t;
    }

    void update_price(float p){
        flight_price = p;
    }

    int available_Seats(){
        return availableSeats;
    }

    void bookSeat(){
        if(availableSeats > 0){
            availableSeats--;
            cout<<"Seat booked"<<endl;
        }
    }

    string get_flight_number(){
        return flight_number;
    }

     

    void display_flight() {
        cout << "Flight Number: " << flight_number << endl;
        // cout << "Flight Name: " << flight_name << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Source: "<< source << endl;
        // for (const auto& src : source) {
        //     cout << src << ", ";
        // }
        // cout << endl;
        cout << "Destination: "<< destination << endl;;
        // for (const auto& des : destination) {
        //     cout << des << ", ";
        // }
        // cout << endl;
        // cout << "Fare/Price: " << flight_price << "/-" << endl;
        // cout << "Departure Time: " << departure_time << endl;
    }  


    // // Write object data to a binary file
    //  void writeToFile(ofstream& outFile) const {
    //     outFile.write(reinterpret_cast<const char*>(this), sizeof(*this));
    //  }

    //  // Read object data from a binary file
    //  void readFromFile(ifstream& inFile) {
        // inFile.read(reinterpret_cast<char*>(this), sizeof(*this));
    //  }


    //  void saveToFile(ofstream &file) const {
    //     size_t length;

    //     // Save flightNumber
    //     length = flight_number.size();
    //     file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    //     file.write(flight_number.c_str(), length);
    //     // Save source
    //     length =  source.size();
    //     file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    //     file.write(source.c_str(), length);

    //     // Save destination
    //     length = destination.size();
    //     file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    //     file.write(destination.c_str(), length);

    //     // Save seats data
    //     file.write(reinterpret_cast<const char*>(&totalSeats), sizeof(totalSeats));
    //     file.write(reinterpret_cast<const char*>(&availableSeats), sizeof(availableSeats));
    // }

    // Load flight details from a binary file
    // void loadFromFile(ifstream &file) {
    //     size_t length;

    //     // Load flightNumber
    //     file.read(reinterpret_cast<char*>(&length), sizeof(length));
    //     flight_number.resize(length);
    //     file.read(&flight_number[0], length);

    //     // Load origin
    //     file.read(reinterpret_cast<char*>(&length), sizeof(length));
    //     source.resize(length);
    //     file.read(&source[0], length);

    //     // Load destination
    //     file.read(reinterpret_cast<char*>(&length), sizeof(length));
    //     destination.resize(length);
    //     file.read(&destination[0], length);

    //     // Load seats data
    //     file.read(reinterpret_cast<char*>(&totalSeats), sizeof(totalSeats));
    //     file.read(reinterpret_cast<char*>(&availableSeats), sizeof(availableSeats));
    // }

    // Display flight details
    void displayFlightDetails() const {
        cout << "Flight Number: " << flight_number << endl;
        cout << "Origin: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }

    // Manually serialize the object to a file
    // void writeToFile(ofstream& out) {
    //     // Write strings with size first, then the actual string



    //     size_t length;
    //     length = flight_number.size();
    //     out.write(reinterpret_cast<char*>(&length), sizeof(length));
    //     out.write(flight_number.c_str(), length);

    //     length = flight_name.size();
    //     out.write(reinterpret_cast<char*>(&length), sizeof(length));
    //     out.write(flight_name.c_str(), length);

    //     length = departure_time.size();
    //     out.write(reinterpret_cast<char*>(&length), sizeof(length));
    //     out.write(departure_time.c_str(), length);

    //     // Write primitive types
    //     out.write(reinterpret_cast<char*>(&totalSeats), sizeof(totalSeats));
    //     out.write(reinterpret_cast<char*>(&availableSeats), sizeof(availableSeats));
    //     out.write(reinterpret_cast<char*>(&flight_price), sizeof(flight_price));

        // Write vectors (source and destination)
        // length = source.size();
        // out.write(reinterpret_cast<char*>(&length), sizeof(length));
        // for (const auto& src : source) {
        //     size_t strLength = src.size();
        //     out.write(reinterpret_cast<char*>(&strLength), sizeof(strLength));
        //     out.write(src.c_str(), strLength);
        // }

        // length = destination.size();
        // out.write(reinterpret_cast<char*>(&length), sizeof(length));
        // for (const auto& des : destination) {
        //     size_t strLength = des.size();
        //     out.write(reinterpret_cast<char*>(&strLength), sizeof(strLength));
        //     out.write(des.c_str(), strLength);
        // }
    // }

    // Manually deserialize the object from a file
    // void readFromFile(ifstream& in) {
    //     // Read strings (first read size, then read the actual string)
    //     size_t length;
    //     in.read(reinterpret_cast<char*>(&length), sizeof(length));
    //     flight_number.resize(length);
    //     in.read(&flight_number[0], length);

    //     in.read(reinterpret_cast<char*>(&length), sizeof(length));
    //     flight_name.resize(length);
    //     in.read(&flight_name[0], length);

    //     in.read(reinterpret_cast<char*>(&length), sizeof(length));
    //     departure_time.resize(length);
    //     in.read(&departure_time[0], length);

    //     // Read primitive types
    //     in.read(reinterpret_cast<char*>(&totalSeats), sizeof(totalSeats));
    //     in.read(reinterpret_cast<char*>(&availableSeats), sizeof(availableSeats));
    //     in.read(reinterpret_cast<char*>(&flight_price), sizeof(flight_price));

        // Read vectors (source and destination)
        // in.read(reinterpret_cast<char*>(&length), sizeof(length));
        // source.clear();
        // for (size_t i = 0; i < length; i++) {
        //     size_t strLength;
        //     in.read(reinterpret_cast<char*>(&strLength), sizeof(strLength));
        //     string src;
        //     src.resize(strLength);
        //     in.read(&src[0], strLength);
        //     source.push_back(src);
        // }

        // in.read(reinterpret_cast<char*>(&length), sizeof(length));
        // destination.clear();
        // for (size_t i = 0; i < length; i++) {
        //     size_t strLength;
        //     in.read(reinterpret_cast<char*>(&strLength), sizeof(strLength));
        //     string des;
        //     des.resize(strLength);
        //     in.read(&des[0], strLength);
        //     destination.push_back(des);
        // }
    // }
};

    // Write object data to a binary file
     void writeToFile(ofstream& outFile, Flight &f){
        outFile.write((char*)&f, sizeof(f));
     }

     // Read object data from a binary file
     void readFromFile(ifstream& inFile, Flight &f) {
        inFile.read((char*)&f, sizeof(f));
     }

void welcome()
{
    ifstream fileopen("welcometext.txt");
    string line;
    while (getline(fileopen, line))
        cout << line << endl;
    cout << "Press any key to continue " << endl;
    getch();
    system("cls");
    fileopen.close();
}

void welcome_animation()
{
    ifstream f1("a1.txt");
    ifstream f2("a2.txt");
    ifstream f3("a3.txt");
    ifstream f4("a4.txt");
    ifstream f5_0("a5_0.txt");
    ifstream f5_1("a5_1.txt");
    ifstream f5_2("a5_2.txt");
    ifstream f5_3("a5_3.txt");
    ifstream f5_4("a5_4.txt");
    ifstream f5_5("a5_5.txt");
    ifstream f6("a6.txt");
    ifstream f7("a7.txt");
    ifstream f8("a8.txt");
    ifstream f9("a9.txt");
    ifstream f10("a10.txt");
    ifstream f11("a11.txt");

    string line;

    while (getline(f1, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f2, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f3, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f4, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f5_0, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f5_1, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f5_2, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f5_3, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f5_4, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f5_5, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f6, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f7, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f8, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f9, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f10, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    while (getline(f11, line))
        cout << line << endl;
    Sleep(250);
    system("cls");

    // close file
    f1.close();
    f2.close();
    f3.close();
    f4.close();
    f5_0.close();
    f5_1.close();
    f5_2.close();
    f5_3.close();
    f5_4.close();
    f5_5.close();
    f6.close();
    f7.close();
    f8.close();
    f9.close();
    f10.close();
    f11.close();
}

void login()
{
    string username, password;
    cout << "\n\nEnter your username: ";
    cin >> username;
    cout << "Enter your Password: ";
    cin >> password;

    ifstream file("login_detail.txt");
     if(!file){
        cout<<"\n\t\x1B[31mServer Error!! (file not open)\n\033[0m\t\t\n";
        Sleep(2000);
        system("cls");
        return;
    }
    string line; 

    while (file.eof() == 0)
    {   file>>line;
        if (line == username)
        {   file>>line;
            if (line == password)
            {
                login_status = true;
                login_user = username;
                break;
            }
        }else getline(file, line);
    } 
    file.close();  
    if (login_status){
        cout << "\n\t\t\033[32m Login Success\033[0m \n\n";
        Sleep(1500);
        system("cls");
        main_menu();
        return;
    }else{
        cout << "\n\t\x1B[31mInvalid username or password \033[0m";
        Sleep(2000);
        system("cls");
        return;
    }
}

void Add_New_Flight() {
    string f_num, f_name, source, destination, departure_time;
    int capacity;
    float price;
    cin.ignore();
    cout << "\nEnter Flight Number: ";
    getline(cin, f_num);
    cout << "\nEnter Flight Name: ";
    getline(cin, f_name);
    cout << "\nEnter Flight source: ";
    getline(cin, source);
    cout << "\nEnter Flight destination: ";
    getline(cin, destination);
    cout << "\nEnter Flight Departure Time(24:00): ";
    getline(cin, departure_time);
    cout << "\nEnter Flight capacity: ";
    cin >> capacity;
    cout << "\nEnter Price: ";
    cin >> price;

    Flight f1(f_num, f_name, departure_time, source, destination, capacity, price);

    ofstream outfile("flight.dat", ios::binary | ios::app);
    if (outfile.is_open()) {
        // f1.writeToFile(outfile);
        writeToFile(outfile,f1);
        outfile.close();
        cout << "\n\x1B[32m New Flight Added Successfully\033[0m\t\t\n\n";
        f1.display_flight();
    //     cout << "\n\nPress any key to continue " << endl;
    //     getch();
    //     system("cls");
    // } else {
    //     cout << "\n\t\x1B[31m !Error opening file Unable to add new flight \033[0\n";
    //     Sleep(1300);
    //     system("cls");
    //     return;
    // }
}

void Display_All_Flight() {
    ifstream infile("flight.dat", ios::binary | ios::in);
    if (infile.is_open()) {
        Flight f1;
        // f1.loadFromFile(infile);
        loadFromFile(infile,f1);
        f1.displayFlightDetails();
        // while (infile.read(reinterpret_cast<char*>(&f1), sizeof(f1))) {
            // f1.display_flight();
        // }

        // while (!infile.eof()) {
        //     f1.readFromFile(infile);
        //     f1.display_flight();
        //     cout << "\n\n";
        // }


        infile.close();
        cout << "\n\nPress any key to continue " << endl;
        getch();
        system("cls");
    }
    //  else {
    //     cout << "\n\t\x1B[31mServer Error!! (file not open)\n\033[0m\t\t\n";
    //     Sleep(2000);
    //     system("cls");
    //     return;
    // }
}

void Update_flight_Detail(){
    system("cls");
    cout<<"\n\033[3;43;30m--- Update Flight Details --- \033[0m\n\n";
    cout<<"1. Enter Flight Number"<<endl<<"2. Choice Flights "<<endl;
    int choice;
    cin>>choice;
    if(choice == 2){
        Display_All_Flight();
    }else if(choice != 1 || choice!= 2){
        cout<<"\n\t\x1B[31m Invalid Choice!!\n\033[0\n";
        Sleep(2000);
        system("cls");
        return ;
    }
    cout<<"\n\nPlease Enter the Flight Number: ";
    string flight_number;
    cin>>flight_number;
    fstream file;
    file.open("flight.dat",ios::binary|ios::app);
    Flight f1;
    file.seekg(0,ios::beg);
    while(file.read((char*)&f1,sizeof(f1))){
        if(f1.get_flight_number() == flight_number){
          while(1){
            cout<<"\nWhich of the following you Update ?\n";
            cout<<"1. Add new Source Place\n";
            cout<<"2. Add new Destination Place\n";
            cout<<"3. Update Departure Time\n";
            cout<<"4. Update Flight Fare\n";
            cout<<"5. Go Back\n";

            int choice;
            cin>>choice;
            if(choice==1){
                cout<<"\nPlease Enter the new Source Place: ";
                string source_place;
                cin>>source_place;
                f1.add_source(source_place);
                cout<<"\n\x1B[32mNew Source Place Added succes :\033[0m" <<source_place<<"\n";
                Sleep(2000);
                return;

            }else if(choice == 2){
                cout<<"\nPlease Enter the new Destination Place: ";
                string destination_place;
                cin>>destination_place;
                f1.add_destination(destination_place);
                cout<<"\n\x1B[32mNew Destination Place Added succes : \033[0m"<<destination_place<<"\n";
                Sleep(2000);
                return;

            }else if(choice == 3){
                cout<<"\nPlease Enter the new Departure Time(24:00): ";
                string departure_time;
                cin>>departure_time;
                f1.update_departure_time(departure_time);
                cout<<"\n\x1B[32m New Departure Time Update succes :\033[0m"<<departure_time<<"\n";
                Sleep(2000);
                return; 
                
            }else if(choice==4){
                cout<<"\nPlease Enter the New Flight Fare: ";
                float price;
                cin>>price;
                f1.update_price(price);
                cout<<"\n\x1B[32m New Flight Fare Update succes :\033[0m"<<price<<"/-\n";
                Sleep(2000);
                return;

            }else if(choice==5){
                 system("cls");
                 return;

            }else{ 
                cout<<"\x1B[31mInvalid Choice!! Please Enter Valid Choice \033[0m\n";
                Sleep(1300);
                system("cls");
            }

           }

        }
    }

}

void admin_menu(){

    cout << "\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\t    AIRLINE RESERVATION SYSTEM\n";
    cout << "   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";

    cout << "   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Administrator Authority \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
    cout<<"\t\t\t\x1B[33m   Admin: "<<administrator_user<<"\033[0m\n"; 

    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 1. Add New Flight\n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 2. Display All Flight\n ";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 3. Update flight Detail\n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 4. --\n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 5. Exit \n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "   Option : ";
    int option;
    cin >> option; 

    if (option == 1)  { 
        Add_New_Flight();
        admin_menu();
    }
    else if (option == 2) {  
        Display_All_Flight();
        admin_menu();
    }
    else if (option == 3) { 
        Update_flight_Detail();
        admin_menu();
    }
    else if (option == 4) {  
        //  login_status = false; 
        //  cout<<"\n\t\x1B[32m--Logout Successfull--\033[0m\t\t\n";
        //  Sleep(2000);
        //  system("cls");
        //  login_menu();
    }
    else if (option == 5) { //Exit
        system("cls"); 
         cout<<"\n\n\n\n\n\n\t\t\t\033[1;47;35m                                                  \033[0m\t\t\n";
         cout<<"\t\t\t\033[1;47;35m--------------  THANKYOU FOR VISITING  -----------\033[0m\t\t\n";
         cout<<"\t\t\t\033[1;47;35m                           ~nishant_ujjwal airline\033[0m\t\t\n\n\n\n\n\n\n";
        exit(0);
    }
    else {
        cout << "\n\t\t\x1B[31mInvalid Input!!\033[0m\t\t";
        Sleep(1300);
        system("cls");
        admin_menu();
    }
}

void admin_login(){
    string username, password;
    cout << "\n\nEnter your Admin username: ";
    cin >> username;
    cout << "Enter your Administrator Password: ";
    cin >> password;

    ifstream file("admin_login_detail.txt");
     if(!file){
        cout<<"\n\t\x1B[31mServer Error!! (file not open)\n\033[0m\t\t\n";
        Sleep(2000);
        system("cls");
        return;
    }
    string line; 

    while (file.eof() == 0){  
        file>>line;
        if(line == username){
           file>>line;
           if(line == password){
              admin_login_status = true;
              administrator_user = username;
              break;
            }
        }else getline(file, line);
    } 

    file.close();  
    if (admin_login_status){
        cout << "\n\t\033[32m Administrator Login Success\033[0m \n\n";
        Sleep(1500);
        system("cls");
        admin_menu();
        return;
    }else{
        cout << "\n\t\x1B[31mInvalid Administrator username or password \033[0m";
        Sleep(2000);
        system("cls");
        return;
    }
}

void Book_Flight_Ticket(){ 
    cout<<"\n\x1B[31m   -- Enter Flight Detail --\033[0m\n\n";
    cin.ignore();
    string departure,arrival;
    cout << "Enter the Departure Place: ";
    getline(cin, departure); 
    cout << "Enter the Arrival Place: ";
    getline(cin, arrival); 
    cout<<"Enter the Departure Date (DD/MM/YYYY): ";
    int date,month,year;
    char c;
    scanf("%d%c%d%c%d",&date,&c,&month,&c,&year);



}

void main_menu()
{
    cout << "\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\t    AIRLINE RESERVATION SYSTEM\n";
    cout << "   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";

    cout << "   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MENU OPTIONS \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
    cout<<"\t\t\t\x1B[33m   user id: @"<<login_user<<"\033[0m\n"; 

    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 1.Book Flight Ticket\n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 2.Cancel Ticket/Reservation\n ";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 3.My Booking \n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 4.Log Out\n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 5. Exit \n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "   Option : ";
    int option;
    cin >> option; 

    if (option == 1)  { //Book Flight Ticket
         Book_Flight_Ticket();
    }
    else if (option == 2) { //Cancel Ticket/Reservation
          
    }
    else if (option == 3) {//My Booking
          
    }
    else if (option == 4) {//logout karne le liye
         login_status = false; 
         cout<<"\n\t\x1B[32m--Logout Successfull--\033[0m\t\t\n";
         Sleep(2000);
         system("cls");
         login_menu();
    }
    else if (option == 5) { //Exit
        system("cls"); 
         cout<<"\n\n\n\n\n\n\t\t\t\033[1;47;35m                                                  \033[0m\t\t\n";
         cout<<"\t\t\t\033[1;47;35m--------------  THANKYOU FOR VISITING  -----------\033[0m\t\t\n";
         cout<<"\t\t\t\033[1;47;35m                           ~nishant_ujjwal airline\033[0m\t\t\n\n\n\n\n\n\n";
        exit(0);
    }
    else {
        cout << "\n\t\t\x1B[31mInvalid Input!!\033[0m\t\t";
        Sleep(1300);
        system("cls");
        main_menu();
    }

}

void signup(){
    string name,username,pass,mob;
    cin.ignore(); 
    cout<<"Enter Your Name: ";
    getline(cin, name); 
    cout<<"Create Your username: ";
    getline(cin, username);
    cout<<"Create Your password: ";
    getline(cin, pass); 
    while(1){
    cout<<"Enter Your 10 digit Mobile Number: ";
    getline(cin, mob);
    if(mob.length()!=10) cout<<"\n\t\x1B[31mInvalid Number! Please Enter Valid Number\n\033[0m\t\t\n";
    else break; 
    }

    ofstream file;
    file.open("login_detail.txt",ios::app);
    if(!file) cout<<"\n\t\x1B[31mServer Error!! (file not open)\n\033[0m\t\t\n";
    file << username << " " << pass << " " << name << " " << mob << endl;  
    file.close();
    cout << "\n\t\x1B[32m------------ Registration Success -----------\033[0m \n";
    signup_ok = true;//bool status 
    Sleep(2000);
    system("cls");
    return;
}

void flight_announcement(){
    ifstream file("flight_announcement.txt");
    if(!file){
        cout<<"\n\t\x1B[31mServer Error!! (file not open)\n\033[0m\t\t\n";
        Sleep(2000);
        system("cls");
        return;
    } 
    cout << "\n\033[1m\033[37m\033[1;47;35m" << "Flight Announcements" << "\033[0m" << endl;
    string line;
    
    while(getline(file,line)){
        cout <<"\x1B[33m"<< line <<"\033[0m"<< endl;  
    }
    file.close();
    cout << "\n\nPress any key to continue " << endl;
    getch();
    system("cls");
}

void details(){
    cout<<"\n\033[1;47;35mDetails\033[0m\t\t\n";
    cout<<"...\n";
    cout<<"...\n";
    cout<<"...\n";
    cout<<"...etc.\n\n";
    cout << "Press any key to continue " << endl;
    getch();
    system("cls");
    return; 
}

void login_menu()
{
    cout << "\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\t    AIRLINE RESERVATION SYSTEM\n";
    cout << "   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";

    cout << "   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd LOGIN OPTIONS \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";

    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 1. Login\n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 2. Sign Up \n ";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 3. Flight Announcements \n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 4. Details \n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 5. Login as Administrator\n";

    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\t 6. Exit\n";
    cout << "\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n";
    cout << "\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    
    if(signup_ok){
    cout<<"\t\x1B[35m  -- Now you can Login --\033[0m\n";
    signup_ok = false;
    }

    cout << "   Option : ";
    int option;
    cin >> option;

    if (option == 1)  {
        login();
        if(!login_status){
        login_menu();
        }
    }
    else if (option == 2) {
         signup();
         login_menu();
    }
    else if (option == 3) {
         flight_announcement();
         login_menu();
    }
    else if (option == 4) {
        details();
        login_menu();
    }
    else if (option == 5) {
        admin_login();
        if(!admin_login_status){
            login_menu();
        }
    }
    else if (option == 6) {
        system("cls"); 
         cout<<"\n\n\n\n\n\n\t\t\t\033[1;47;35m                                                  \033[0m\t\t\n";
         cout<<"\t\t\t\033[1;47;35m--------------  THANKYOU FOR VISITING  -----------\033[0m\t\t\n";
         cout<<"\t\t\t\033[1;47;35m                           ~nishant_ujjwal airline\033[0m\t\t\n\n\n\n\n\n\n";
        exit(0);
    }
    else {
        cout << "\n\t\t\x1B[31mInvalid Input!!\033[0m\t\t";
        Sleep(1000);
        system("cls");
        login_menu();
    }
    
}

 
int main()
{
    // welcome();
    // welcome_animation();
    // login_menu(); 
    // Flight f;
    Add_New_Flight();
    // Flight st;
    Display_All_Flight();
    

    // ofstream out;
    // Flight st;
    // out.open("flight_1.dat", ios::binary | ios::app);
    // int i=0;
    // while(i<1) // use multiple record...
    // {
    //    Add_New_Flight();
    //     out.write( (char*)&st, sizeof(st));
    //     i++;
    // }
    // out.close();

    // ifstream in;
    // in.open("flight_1.dat",ios::binary | ios::in);
    // int v=0;
    // while(in.read((char *)&st, sizeof(st))) // use multiple record...
    // { 
    //     st.displayFlightDetails(); 
        //for searching ----------
        // if(st.Roll()==2){
        //     cout << "\nRecord found";
        // }
    }
    // in.close();

//   // write in the file in binarry formet (.dat)
//     ofstream out;
//     student st;
//     out.open("student.dat", ios::binary);
//     int i=0;
//     while(i<2) // use multiple record...
//     {
//         st.input();
//         out.write( (char*)&st, sizeof(st));
//         i++;
//     }
//     out.close();

// //------------------read-------------------------------------
//     ifstream in;
//     in.open("student.dat",ios::binary | ios::in);
//     int v=0;
//     while(in.read((char *)&st, sizeof(st))) // use multiple record...
//     { 
//         st.display(); 
//         //for searching ----------
//         if(st.Roll()==2){
//             cout << "\nRecord found";
//         }
//     }
//     in.close();



    cout << "THANKYOU" << "login";

    return 0;
}

// Login
// Sign Up
// Announcements
// Details
// Exit

// cout << "\n -------------------------------------------------------------" << endl;
// cout << "               NISHANT-UJJAWAL™ AIRLINE RESERVATION SYSTEM";
// cout << "\n -------------------------------------------------------------" << endl;
// cout << "\n ----------------------- MENU OPTIONS ------------------------ " << endl;
// cout << "\n 1. Flight Information" << endl;
// cout << "\n 2. Flight Booking" << endl;
// cout << "\n 3. Flight Cancellation" << endl;
// cout << "\n 4. Flight Status" << endl;
// cout << "\n 5. Flight Schedule" << endl;
// cout << "\n\n                 [NISHANT-UJJWAL] ";
