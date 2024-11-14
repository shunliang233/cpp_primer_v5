// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <set>
#include "Sales_data.h"
using std::cout;
using std::endl;
using std::multiset;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookStore(compareIsbn);
}