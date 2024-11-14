// Windows Powershell: g++ -std=c++11 -Wall -o 1.21.exe 1.21.cpp ; gc add_items.txt | ./1.21.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 1.21.out 1.21.cpp ; ./1.21.out < add_items.txt
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;

    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
}