#pragma once
#include <string>
#include <iostream>
using std::istream;
using std::ostream;
using std::string;

// 前置声明。想定义 Sales_data 类需要先定义 read 函数, 而想定义 read 函数需要先定义 Sales_data 类, 使用前置声明就能解决这个问题。
struct Sales_data;
istream &read(istream &is, Sales_data &item);

// 定义类
struct Sales_data
{
    // 数据成员
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;

    // 构造函数
    Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {} // 显式的默认构造函数
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(istream &is)
    {
        read(is, *this);
    }

    // 函数成员
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

// 定义类相关的函数
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

// 定义类成员函数
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}