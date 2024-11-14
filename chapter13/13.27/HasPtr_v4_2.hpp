#include <string>

// 2024-11-04 v4_2

// HasPtr 行为像指针
// 添加一个应用计数成员变量，来管理内存的释放
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0), use(new std::size_t(1)) {} // 默认构造函数
    HasPtr(const HasPtr &a)
        : ps(a.ps), i(a.i), use(a.use) { ++*use; } // 拷贝构造函数
    HasPtr &operator=(const HasPtr &);             // 拷贝赋值运算符
    ~HasPtr();                                     // 析构函数

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

// 析构函数
inline HasPtr::~HasPtr()
{ // 如果引用计数在析构了这个 HasPtr 对象后变为 0, 就应该释放内存
    // 如果引用计数不为 0, 则不释放内存，但是引用计数也已经自减过了
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
};

// 拷贝赋值运算符
inline HasPtr &HasPtr::operator=(const HasPtr &rhs)
{ // 拷贝赋值运算符一般要执行拷贝构造函数和析构函数的工作
    // 先增 use 再减 rhs.use, 可以保证在自赋值时 use 不可能在自减后为 0, 从而释放内存
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}
