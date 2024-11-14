#include "StrVec.hpp"
using std::pair;
using std::string;
using std::uninitialized_copy;

/**
 * @brief 定义静态成员变量时进行默认初始化
 */
std::allocator<std::string> StrVec::alloc;

/**
 * @brief 检查分配的空间是否用完了，如果用完就重新分配。
 */
void StrVec::chk_n_alloc()
{
    if (size() == capacity())
        reallocate();
}

/**
 * @brief 分配一段新的内存，存储给定 string 的副本
 * @param b 给定的第一个 string 的指针
 * @param e 给定的最后一个 string 的指针
 * @return 新内存片段的第一个和最后一个指针
 */
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

/**
 * @brief 在确保已分配内存的情况下，先析构所有 string, 再回收整段内存
 */
void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements; /*空*/)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

/**
 * @brief 将旧内存中的 string 移动到新内存中，使用 std::move 避免拷贝 string
 */
void StrVec::reallocate()
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
StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

/**
 * @brief 析构函数，先析构存储的 string, 再释放内存
 */
StrVec::~StrVec() { free(); }

/**
 * @brief 拷贝赋值运算符，先分配新的内存再释放旧内存，以允许自赋值
 */
StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

/**
 * @brief 插入新的 string。
 * 先确保有足够的空间，不够的话就分配新的，再在第一个空位处构造 string。
 * @param s 被插入的 string
 */
void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
