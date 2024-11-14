// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include "Sales_data.h"

int main()
{
    double price = 0; // 中间变量

    // 读入两条数据
    Sales_data data1, data2;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    // 输出两个对象的和
    if (data1.isbn() == data2.isbn())
    {
        data1.combine(data2);
        std::cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << " ";
        if (data1.units_sold != 0)
            std::cout << data1.revenue / data1.units_sold << std::endl; // 平均价格
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}