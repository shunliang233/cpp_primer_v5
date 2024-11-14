#pragma once
#include <string>
#include <iostream>
using std::istream;
using std::ostream;
using std::string;

// 定义类
class Person
{
    // 声明友元函数
    friend istream &read(istream &is, Person &item);
    friend ostream &print(ostream &os, const Person &item);

public:
    // 构造函数
    Person() = default;
    Person(const string &s1, const string &s2) : MingZi(s1), DiZhi(s2) {}
    Person(istream &is) { read(is, *this); }

    // 函数成员
    string name() const { return MingZi; }
    string address() const { return DiZhi; }

private:
    string MingZi;
    string DiZhi;
};

// 定义友元函数
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
