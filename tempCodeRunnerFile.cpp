#include <iostream>
#include <string>
using namespace std;

void print_line(string space, char start, char mid, char end, int length, string end_endl="\n\n") // Function to print a line with given characters and length
{
    cout<< space << start;
    for (int i = 0; i < length; i++)
        cout << mid;
    cout << end << end_endl;
}

int main() {

 print_line("\n\n\n",'|', '-', '|', 101,"");

    return 0;
}
