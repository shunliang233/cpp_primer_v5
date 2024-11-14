// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data data1;
    Sales_data data2("0-201-78345-X");
    Sales_data data3("0-201-78345-X", 3, 20.00);
    Sales_data data4(cin);

    print(cout, data1) << endl;
    print(cout, data2) << endl;
    print(cout, data3) << endl;
    print(cout, data4) << endl;
}