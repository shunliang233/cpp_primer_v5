#include <string>

// 2024-11-04 v4
// 拷贝赋值运算符要释放 ps 原先指向的内存，防止内存泄漏
// HasPtr_v4 行为像值

class HasPtr_v4
{
public:
    HasPtr_v4(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) {} // 默认构造函数
    HasPtr_v4(const HasPtr_v4 &a)
        : ps(new std::string(*a.ps)), i(a.i) {} // 拷贝构造函数
    ~HasPtr_v4() { delete ps; }                    // 析构函数
    HasPtr_v4 &operator=(const HasPtr_v4 &);          // 拷贝赋值运算符

private:
    std::string *ps;
    int i;
};

// newp 的作用使一个 HasPtr_v4 对象拷贝给自身时也不出问题
// 先拷贝的 newp 也可以保证拷贝过程遇到异常终止时，原先的指针 ps 还是有意义的（异常安全）
inline HasPtr_v4 &HasPtr_v4::operator=(const HasPtr_v4 &a)
{
    auto newp = new std::string(*a.ps);
    delete ps;
    ps = newp;
    i = a.i;
    return *this;
}