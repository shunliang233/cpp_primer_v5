#pragma once
#include <string>
#include <iostream>
using std::istream;
using std::ostream;
using std::string;

// 前置声明
struct Person;
istream &read(istream &is, Person &item);

// 定义类
struct Person
{
    // 数据成员
    string MingZi;
    string DiZhi;

    // 构造函数
    Person() = default;
    Person(const string &s1, const string &s2) : MingZi(s1), DiZhi(s2) {}
    Person(istream &is) { read(is, *this); }

    // 函数成员
    string name() const { return MingZi; }
    string address() const { return DiZhi; }
};

// 定义类相关的函数
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
