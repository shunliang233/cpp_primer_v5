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
    Sales_data s("978-7-121-15535-2", 2, 128);
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookStore(compareIsbn);  // multiset 对象
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>::iterator it = bookStore.begin(); // iterator 对象
    // 不能通过 it 进行赋值，因为 set::iterator 类型也是只读 set 元素的
}