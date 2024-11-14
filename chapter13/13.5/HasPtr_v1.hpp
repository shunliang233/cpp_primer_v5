#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {} // 默认构造函数
    HasPtr(const HasPtr &a) : ps(new std::string(*a.ps)), i(a.i) {}      // 拷贝构造函数

private:
    std::string *ps;
    int i;
};