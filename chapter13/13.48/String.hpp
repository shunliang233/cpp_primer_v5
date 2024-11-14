#pragma once
#include <memory>

class String
{
public:
    // 构造，析构，拷贝
    String() = default;
    String(const String &);
    String(const char *);
    String &operator=(const String &);
    ~String();

    // 公有接口
    void push_back(const char &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }

private:
    // 私有数据成员
    static std::allocator<char> alloc; // 仅是声明，必须在外部定义
    char *elements = nullptr;
    char *first_free = nullptr;
    char *cap = nullptr;

    // 工具函数
    void chk_n_alloc();
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void free();
    void reallocate();
};