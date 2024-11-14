// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;

int main()
{
    // 读入两条数据
    Sales_data data1, data2;
    read(cin, data1);
    read(cin, data2);

    // 输出两个对象的和
    if (data1.isbn() == data2.isbn())
    {
        data1.combine(data2);
        print(cout, data1);
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}