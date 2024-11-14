#pragma once
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    // 拷贝控制
    StrBlob() = default;
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {};
    StrBlob(const StrBlob &s) : data(std::make_shared<std::vector<std::string>>()) {}; // 拷贝构造函数
    StrBlob &operator=(const StrBlob &);                                               // 拷贝赋值运算符
    // 不需要调用 check 的函数
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void push_back(std::string &&t) { data->push_back(std::move(t)); }
    // 需要调用 check 的函数
    void pop_back();
    void do_front() const { check(0, "front on empty StrBlob"); };
    std::string &front();
    const std::string &front() const;
    void do_back() const { check(0, "back on empty StrBlob"); };
    std::string &back();
    const std::string &back() const;
    // 需要先定义 StrBlobPtr 类型
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data = std::make_shared<std::vector<std::string>>(); // 默认初始化为空 std::shared_ptr 指针，空悬指针是不能解引用的，因此要在类内初始化分配为非空悬指针
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
public:
    // 构造函数
    StrBlobPtr() = default;
    StrBlobPtr(StrBlob &a, StrBlob::size_type sz = 0) : wptr(a.data), curr(sz) {}
    // 代替运算符的函数
    std::string &deref() const;
    StrBlobPtr &incr();
    bool equal(const StrBlobPtr &) const;

private:
    std::weak_ptr<std::vector<std::string>> wptr;
    StrBlob::size_type curr = 0;
    std::shared_ptr<std::vector<std::string>> check(StrBlob::size_type, const std::string &) const;
};

// ConstStrBlobPtr 类型对象用于指向 const StrBlob 类型对象
// 其实 const StrBlob 中仅有 shared_ptr 数据成员被设置为了 const, 并不是指针指向的 vector 被设置成了 const
// 但是由于 const StrBlob 中的所有能更改 vector 的接口函数都被禁用了，因此实际上 vector 也变成无法更改的了
// 首先 ConstStrBlobPtr 的构造函数需要支持接受 const StrBlob 类型
// 由于不能通过 ConstStrBlobPtr 更改 vector, 因此第一步需要将 weak_ptr 指向 const vector
// 后面的就都是按照 weak_ptr 的类型进行修改了: check 函数的返回类型、deref 函数的返回类型
// 这些都改完之后应该就可以了（查了官网给的练习题答案，没有这题的参考答案，因此只能认为自己写的没有问题了）
class ConstStrBlobPtr
{
public:
    // 构造函数
    ConstStrBlobPtr() = default;
    ConstStrBlobPtr(const StrBlob &a, StrBlob::size_type sz = 0) : wptr(a.data), curr(sz) {} // 构造函数可以接受 const StrBlob
    // 代替运算符的函数
    const std::string &deref() const;
    ConstStrBlobPtr &incr();

private:
    std::weak_ptr<const std::vector<std::string>> wptr;
    StrBlob::size_type curr = 0;
    std::shared_ptr<const std::vector<std::string>> check(StrBlob::size_type, const std::string &) const;
};
