#pragma once
#include <string>
#include <iostream>
using std::istream;
using std::ostream;
using std::string;

// 定义类
struct Sales_data
{
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;

    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

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