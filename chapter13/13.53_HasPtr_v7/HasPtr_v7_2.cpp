#include <iostream>
#include "HasPtr_v7_2.hpp"
using std::cout;
using std::endl;

// 交换函数
inline void swap(HasPtr_v7_2 &lhs, HasPtr_v7_2 &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// 拷贝赋值运算符
inline HasPtr_v7_2 &HasPtr_v7_2::operator=(const HasPtr_v7_2 &a)
{
    auto newp = new std::string(*a.ps);
    delete ps;
    ps = newp;
    i = a.i;
    return *this;
}

// 移动赋值运算符，用 inline 会报错，不知道为什么
HasPtr_v7_2 &HasPtr_v7_2::operator=(HasPtr_v7_2 &&p) noexcept
{
    if (this != &p)
    {
        delete ps;
        ps = p.ps;
        i = p.i;
        p.ps = nullptr;
    }
    return *this;
}

// 小于运算符
// 好神奇啊，如果 this 不是 const 而 rhs 是 const, 就会报错
inline bool HasPtr_v7_2::operator<(const HasPtr_v7_2 &rhs) const
{
    if (*this->ps < *rhs.ps)
        return true;
    else
        return false;
}