// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include "Sales_data.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data item1("0-201-78345-X", 3, 20.00);
    cout << endl;
    Sales_data item2; // 写空的圆括号表示函数声明，调用默认构造函数不能使用圆括号
    cout << endl;
    Sales_data item3("0-201-78345-X");
    cout << endl;
    Sales_data item4(cin);
}