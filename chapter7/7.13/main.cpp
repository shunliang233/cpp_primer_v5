// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include "Sales_data.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;


// 只可能用 istream 构造函数代替原先的 read 函数的功能，但是两个 read 函数都在条件表达式中，条件表达式中不能使用带圆括号的初始化表达式。
int main()
{
    Sales_data total(cin);
    Sales_data trans;
    while (read(cin, trans))
    {
        if (total.isbn() == trans.isbn())
        {
            total.combine(trans);
        }
        else
        {
            print(cout, total) << endl;
            total = trans;
        }
    }
    print(cout, total) << endl;
}