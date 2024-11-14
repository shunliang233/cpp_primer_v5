// Windows Powershell: g++ -std=c++11 -Wall -o 2.42.exe 2.42.cpp ; gc data.txt | ./2.42.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 2.42.out 2.42.cpp ; ./2.42.out < data.txt

#include <iostream>
//#include <string>
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
    if (data1.bookNo == data2.bookNo)
    {
        int totalCnt = data1.units_sold + data2.units_sold;  // 总销售量
        double totalRevenue = data1.revenue + data2.revenue; // 总销售额
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl; // 平均价格
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