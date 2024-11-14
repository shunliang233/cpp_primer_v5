#pragma once
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>

class StrVec
{
public:
    // 构造，析构，拷贝
    StrVec() {}                 // 默认构造函数
    StrVec(const StrVec &);     // 拷贝构造函数
    StrVec(StrVec &&) noexcept; // 移动构造函数
    StrVec(std::initializer_list<std::string>);
    StrVec &operator=(const StrVec &);     // 拷贝赋值运算符
    StrVec &operator=(StrVec &&) noexcept; // 移动赋值运算符
    ~StrVec();                             // 析构函数

    // 与 vector 类似的公有接口
    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    // 私有数据成员
    static std::allocator<std::string> alloc; // 仅是声明，必须在外部定义
    std::string *elements = nullptr;
    std::string *first_free = nullptr;
    std::string *cap = nullptr;

    // 工具函数
    void chk_n_alloc();
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate();
};
