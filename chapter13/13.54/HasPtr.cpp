#include <iostream>
#include "HasPtr.hpp"
using std::cout;
using std::endl;

// 交换函数
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// 拷贝和移动赋值运算符，用 inline 会报错，不知道为什么
HasPtr &HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}

// 移动赋值运算符
HasPtr &HasPtr::operator=(HasPtr &&p) noexcept
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
inline bool HasPtr::operator<(const HasPtr &rhs) const
{
    if (*this->ps < *rhs.ps)
        return true;
    else
        return false;
}