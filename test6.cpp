#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Class NestedClass (contains an int and a string)
class NestedClass {
public:
    int num; 
    string text;

    NestedClass() : num(0), text("") {}  // Default constructor
    NestedClass(int n, const string& t) : num(n), text(t) {}

    // Method to serialize NestedClass to binary file
    void writeToFile(ofstream& outFile) const {
        outFile.write(reinterpret_cast<const char*>(&num), sizeof(num)); // Write integer

        // Write the size of the string, then the string data
        size_t textSize = text.size();
        outFile.write(reinterpret_cast<const char*>(&textSize), sizeof(textSize));
        outFile.write(text.c_str(), textSize);  // Write the actual string data
    }

    // Method to deserialize NestedClass from binary file
    void readFromFile(ifstream& inFile) {
        inFile.read(reinterpret_cast<char*>(&num), sizeof(num));  // Read integer

        // Read the size of the string, then the string data
        size_t textSize;
        inFile.read(reinterpret_cast<char*>(&textSize), sizeof(textSize));
        text.resize(textSize);  // Resize the string to the correct size
        inFile.read(&text[0], textSize);  // Read the actual string data
    }

    // Display the NestedClass data
    void display() const {
        cout << "Number: " << num << ", Text: " << text << endl;
    }
};

// Class MyClass containing a vector of NestedClass objects
class MyClass {
public:
    vector<NestedClass> nestedObjects;

    MyClass() = default;  // Default constructor
    MyClass(const vector<NestedClass>& objects) : nestedObjects(objects) {}

    // Method to serialize MyClass to binary .dat file
    void writeToFile(const string& filename) const {
        ofstream outFile(filename, ios::binary);

        // Write the size of the vector first
        size_t vectorSize = nestedObjects.size();
        outFile.write(reinterpret_cast<const char*>(&vectorSize), sizeof(vectorSize));

        // Write each NestedClass object to the file
        for (const auto& obj : nestedObjects) {
            obj.writeToFile(outFile);
        }

        outFile.close();
    }

    // Method to deserialize MyClass from binary .dat file
    void readFromFile(const string& filename) {
        ifstream inFile(filename, ios::binary);

        // Read the size of the vector
        size_t vectorSize;
        inFile.read(reinterpret_cast<char*>(&vectorSize), sizeof(vectorSize));

        // Resize the vector and read each NestedClass object
        nestedObjects.resize(vectorSize);
        for (auto& obj : nestedObjects) {
            obj.readFromFile(inFile);
        }

        inFile.close();
    }

    // Display the MyClass data
    void display() const {
        for (const auto& obj : nestedObjects) {
            obj.display();
        }
    }
};

int main() {
    // Create some NestedClass objects
    NestedClass obj1(10, "Hello");
    NestedClass obj2(20, "World");
    vector<NestedClass> vec = {obj1, obj2};

    // Create MyClass object with the vector of NestedClass objects
    MyClass myObj(vec);

    // Write the MyClass object to a binary .dat file
    myObj.writeToFile("myclass.dat");

    // Create a new MyClass object and load the data from the .dat file
    MyClass newObj;
    newObj.readFromFile("myclass.dat");

    // Display the data of the new object
    newObj.display();

    return 0;
}














#include <iostream>
#include <fstream>
#include <cstring>  // For strcpy, strncpy
#include <string>   // For std::string
#include <vector>   // For std::vector

using namespace std;

class Passenger {
private:
    char name[30]; // For example, 30 characters for the passenger name
    char passport_no[20]; // For the passport number

public:
    Passenger() {}

    // Parameterized constructor
    Passenger(string n, string p) {
        strncpy(name, n.c_str(), sizeof(name) - 1);
        name[29] = '\0';  // Ensure null termination

        strncpy(passport_no, p.c_str(), sizeof(passport_no) - 1);
        passport_no[19] = '\0';  // Ensure null termination
    }

    // Method to save passenger details to binary file
    void save(ofstream &file) {
        file.write(reinterpret_cast<const char*>(&name), sizeof(name));
        file.write(reinterpret_cast<const char*>(&passport_no), sizeof(passport_no));
    }

    // Method to read passenger details from binary file
    void read(ifstream &file) {
        file.read(reinterpret_cast<char*>(&name), sizeof(name));
        file.read(reinterpret_cast<char*>(&passport_no), sizeof(passport_no));
    }

    // Method to display passenger details
    void display() {
        cout << "Passenger Name: " << name << ", Passport No: " << passport_no << endl;
    }
};
