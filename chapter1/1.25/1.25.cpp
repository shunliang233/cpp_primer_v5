// Windows Powershell: g++ -std=c++11 -Wall -o 1.25.exe 1.25.cpp ; gc book_sales.txt | ./1.25.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.25.out 1.25.cpp ; ./1.25.out < book_sales.txt
#include <iostream>
#include "Sales_item.h"

// TODO: 不能处理同一本书跳着出现的情况
int main()
{
    Sales_item total; // 一本书的总销售额
    if (std::cin >> total)
    {
        Sales_item trans;
        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
                total += trans; // 相同的书求和
            else
            {
                // 打印前一本书的数据，并开始处理下一本书
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl; // 最后一本书别忘记打印
        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
}