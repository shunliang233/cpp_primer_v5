#pragma once
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>

class StrVec
{
public:
    // 构造，析构，拷贝
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec(std::initializer_list<std::string>);
    StrVec &operator=(const StrVec &);
    ~StrVec();

    // 与 vector 类似的公有接口
    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    // 私有数据成员
    static std::allocator<std::string> alloc; // 仅是声明，必须在外部定义
    std::string *elements;
    std::string *first_free;
    std::string *cap;

    // 工具函数
    void chk_n_alloc();
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate();
};
