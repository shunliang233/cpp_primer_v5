#pragma once
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

// 定义类
class Sales_data
{
    // 友元函数声明
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);

public:
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) { cout << 1 << endl; }
    Sales_data() : Sales_data("", 0, 0) { cout << 2 << endl; }
    Sales_data(const string &s) : Sales_data(s, 0, 0) { cout << 3 << endl; }
    Sales_data(istream &is) : Sales_data()
    {
        read(is, *this);
        cout << 4 << endl;
    }
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const;
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

// 定义友元函数
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
inline double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}