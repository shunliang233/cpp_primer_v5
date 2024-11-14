#include <string>
#include <iostream>

// 2024-11-05 v6
// HasPtr 行为像值
// 定义 < 运算符

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    // 构造和析构
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) {} // 默认构造函数
    HasPtr(const HasPtr &a)
        : ps(new std::string(*a.ps)), i(a.i) {} // 拷贝构造函数
    ~HasPtr() { delete ps; }                    // 析构函数

    // 运算符
    HasPtr &operator=(HasPtr);            // 拷贝赋值运算符
    bool operator<(const HasPtr &) const; // 小于运算符

private:
    // 数据成员
    std::string *ps;
    int i;
};

// 交换函数
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "Run swap 1 time." << std::endl;
}

// 拷贝赋值运算符
inline HasPtr &HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
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