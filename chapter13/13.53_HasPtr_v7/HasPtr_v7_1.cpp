#include <iostream>
#include "HasPtr_v7_1.hpp"
using std::cout;
using std::endl;

// 交换函数
inline void swap(HasPtr_v7_1 &lhs, HasPtr_v7_1 &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// 拷贝和移动赋值运算符，用 inline 会报错，不知道为什么
HasPtr_v7_1 &HasPtr_v7_1::operator=(HasPtr_v7_1 rhs)
{
    swap(*this, rhs);
    return *this;
}

// 小于运算符
// 好神奇啊，如果 this 不是 const 而 rhs 是 const, 就会报错
inline bool HasPtr_v7_1::operator<(const HasPtr_v7_1 &rhs) const
{
    if (*this->ps < *rhs.ps)
        return true;
    else
        return false;
}