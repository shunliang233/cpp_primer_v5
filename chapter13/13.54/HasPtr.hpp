#pragma once
#include <string>

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    // 构造和析构
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) {} // 默认构造函数
    HasPtr(const HasPtr &a)
        : ps(new std::string(*a.ps)), i(a.i) {} // 拷贝构造函数
    HasPtr(HasPtr &&p) noexcept
        : ps(p.ps), i(p.i) { p.ps = 0; } // 移动构造函数
    ~HasPtr() { delete ps; }             // 析构函数

    // 运算符
    HasPtr &operator=(HasPtr);            // 拷贝和移动赋值运算符
    HasPtr &operator=(HasPtr &&) noexcept; // 移动赋值运算符
    bool operator<(const HasPtr &) const; // 小于运算符

private:
    // 数据成员
    std::string *ps;
    int i;
};