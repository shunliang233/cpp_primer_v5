// Windows Powershell: g++ -std=c++11 -Wall -o 1.23.exe 1.23.cpp ; gc book_sales.txt | ./1.23.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.23.out 1.23.cpp ; ./1.23.out < book_sales.txt
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item current;      // 用于保存当前交易记录
    if (std::cin >> current) // 先确保输入文件中拥有交易记录
    {
        Sales_item next; // 用于保存下一条交易记录，用于和当前交易记录进行比较
        int cnt = 1;     // 当前 ISBN 交易记录的计数器，目前已拥有一条交易记录
        while (std::cin >> next)
        {
            if (current.isbn() == next.isbn())
                cnt++;
            else
            {
                std::cout << current.isbn() << " has " << cnt << " sale items." << std::endl;
                // 进入下一个 ISBN 的统计循环
                current = next;
                cnt = 1;
            }
        }
        // 最后一个 ISBN 在 while 循环中没有输出
        std::cout << current.isbn() << " has " << cnt << " sale items." << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
}