#include <iostream>
#include "String.hpp"
using std::cout;
using std::endl;
using std::pair;
using std::uninitialized_copy;

/**
 * @brief 定义静态成员变量时进行默认初始化
 */
std::allocator<char> String::alloc;

/**
 * @brief 检查分配的空间是否用完了，如果用完就重新分配。
 */
void String::chk_n_alloc()
{
    if (size() == capacity())
        reallocate();
}

/**
 * @brief 分配一段新的内存，存储给定 char 的副本
 * @param b 给定的第一个 char 的指针
 * @param e 给定的最后一个 char 的指针
 * @return 新内存片段的第一个和最后一个指针
 */
pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

/**
 * @brief 在确保已分配内存的情况下，先析构所有 string, 再回收整段内存
 */
void String::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements; /*空*/)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

/**
 * @brief 将旧内存中的 string 移动到新内存中，使用 std::move 避免拷贝 string
 */
void String::reallocate()
{
    // 分配新内存
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    // 指针指向新旧内存中各自的第一个位置
    auto dest = newdata;
    auto elem = elements;
    // 将 string 从旧内存移动到新内存，并释放就内存
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    // 更新数据成员
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

/**
 * @brief 拷贝构造函数，仅分配刚好够用的内存空间
 */
String::String(const String &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

/**
 * @brief 析构函数，先析构存储的 string, 再释放内存
 */
String::~String()
{
    free();
}

/**
 * @brief 拷贝赋值运算符，先分配新的内存再释放旧内存，以允许自赋值
 */
String &String::operator=(const String &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

/**
 * @brief 接受 C 风格字符串的构造函数
 */
String::String(const char *c)
{ // 首先保证 c 不是一个空指针
    if (c)
    { // 只要指向的不是 '\0' 就 push_back, 并处理下一个字符
        while (*c != '\0')
        {
            this->push_back(*c++);
        }
    }
}

/**
 * @brief 插入新的 char。
 * 先确保有足够的空间，不够的话就分配新的，再在第一个空位处构造 char。
 * @param c 被插入的 char
 */
void String::push_back(const char &c)
{
    chk_n_alloc();
    alloc.construct(first_free++, c);
}