// Windows Powershell: g++ -std=c++11 -Wall -o 1.20.exe 1.20.cpp ; gc book_sales.txt | ./1.20.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.20.out 1.20.cpp ; ./1.20.out < book_sales.txt
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    while (std::cin >> item)
    {
        std::cout << item << std::endl;
    }
    return 0;
}
