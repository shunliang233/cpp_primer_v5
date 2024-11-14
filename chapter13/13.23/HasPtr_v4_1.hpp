#include <string>

// 2024-11-04 v4_1
// 拷贝赋值运算符要释放 ps 原先指向的内存，防止内存泄漏
// HasPtr 行为像值
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) {} // 默认构造函数
    HasPtr(const HasPtr &a)
        : ps(new std::string(*a.ps)), i(a.i) {} // 拷贝构造函数
    ~HasPtr() { delete ps; }                    // 析构函数
    HasPtr &operator=(const HasPtr &);          // 拷贝赋值运算符

private:
    std::string *ps;
    int i;
};

// newp 的作用使一个 HasPtr 对象拷贝给自身时也不出问题
// 先拷贝的 newp 也可以保证拷贝过程遇到异常终止时，原先的指针 ps 还是有意义的（异常安全）
inline HasPtr &HasPtr::operator=(const HasPtr &a)
{
    auto newp = new std::string(*a.ps);
    delete ps;
    ps = newp;
    i = a.i;
    return *this;
}