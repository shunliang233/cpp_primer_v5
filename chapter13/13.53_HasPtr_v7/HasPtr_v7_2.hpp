#pragma once
#include <string>

class HasPtr_v7_2
{
    friend void swap(HasPtr_v7_2 &, HasPtr_v7_2 &);

public:
    // 构造和析构
    HasPtr_v7_2(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) {} // 默认构造函数
    HasPtr_v7_2(const HasPtr_v7_2 &a)
        : ps(new std::string(*a.ps)), i(a.i) {} // 拷贝构造函数
    HasPtr_v7_2(HasPtr_v7_2 &&p) noexcept
        : ps(p.ps), i(p.i) { p.ps = 0; } // 移动构造函数
    ~HasPtr_v7_2() { delete ps; }        // 析构函数

    // 运算符
    HasPtr_v7_2 &operator=(const HasPtr_v7_2 &);     // 拷贝赋值运算符
    HasPtr_v7_2 &operator=(HasPtr_v7_2 &&) noexcept; // 移动赋值运算符
    bool operator<(const HasPtr_v7_2 &) const;       // 小于运算符

private:
    // 数据成员
    std::string *ps;
    int i;
};