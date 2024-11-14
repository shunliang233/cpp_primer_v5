#include <string>

// 2024-11-05 v5
// HasPtr 行为像值
// 添加优化的 swap 函数
// 优化拷贝赋值运算符

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
    HasPtr &operator=(HasPtr); // 拷贝赋值运算符

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
}

// 拷贝赋值运算符
inline HasPtr &HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}