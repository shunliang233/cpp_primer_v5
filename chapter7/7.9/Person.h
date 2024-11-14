#pragma once
#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

// 定义类
struct Person
{
    string MingZi;
    string DiZhi;
    string name() const { return MingZi; }
    string address() const { return DiZhi; }
};

// 定义读取和打印函数
istream &read(istream &is, Person &item)
{
    is >> item.MingZi >> item.DiZhi;
    return is;
}
ostream &print(ostream &os, const Person &item)
{
    os << item.name() << " " << item.address();
    return os;
}

