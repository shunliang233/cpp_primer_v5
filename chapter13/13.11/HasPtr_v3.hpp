#include <string>

// 2024-03-26 v3
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {} // 默认构造函数
    HasPtr(const HasPtr &a) : ps(new std::string(*a.ps)), i(a.i) {}                // 拷贝构造函数
    ~HasPtr() { delete ps; }                                                       // 析构函数
    
    // 2024-11-04 这里忘记释放 ps 原先指向的内存，会导致内存泄漏
    HasPtr &operator=(const HasPtr &a)                                             // 拷贝赋值运算符
    {
        ps = new std::string(*a.ps);
        i = a.i;
        return *this;
    }

private:
    std::string *ps;
    int i;
};