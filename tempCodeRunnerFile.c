#include <iostream>
#include <string>
using namespace std;

void print_line(string space, string start, string mid, string end, int length, string end_endl="\n\n") // Function to print a line with given characters and length
{
    cout<< space << start;
    for (int i = 0; i < length; i++)
        cout << mid;
    cout << end << end_endl;
}

int main() {

 print_line("\n\n\n",'|', '-', '|', 101);
 print_line("\n\n\t","char(218)", "char(196)", "char(191)", 104);

    return 0;
}
