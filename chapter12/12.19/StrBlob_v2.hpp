#pragma once
#include <vector>
#include <string>
#include <stdexcept>

// 2024-11-01 v2
// 在头文件中不要用 using
// StrBlob 类中的 front 和 back 重载函数调用 do_front 和 do_back
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    // 构造函数
    StrBlob() = default;
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {};
    // 不需要调用 check 的函数
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    // 需要调用 check 的函数
    void pop_back();
    void do_front() const { check(0, "front on empty StrBlob"); };
    std::string &front();
    const std::string &front() const;
    void do_back() const { check(0, "back on empty StrBlob"); };
    std::string &back();
    const std::string &back() const;
    StrBlobPtr begin(); // 不能使用 StrBlobPtr 类型中的内容
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data = std::make_shared<std::vector<std::string>>(); // 默认初始化为空 std::shared_ptr 指针，空悬指针是不能解引用的，因此要在类内初始化分配为非空悬指针
    void check(size_type i, const std::string &msg) const;
};
void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
std::string &StrBlob::front()
{
    do_front();
    return data->front();
}
const std::string &StrBlob::front() const
{
    do_front();
    return data->front();
}
std::string &StrBlob::back()
{
    do_back();
    return data->back();
}
const std::string &StrBlob::back() const
{
    do_back();
    return data->back();
}

class StrBlobPtr
{
public:
    StrBlobPtr() = default;
    StrBlobPtr(StrBlob &a, StrBlob::size_type sz = 0) : wptr(a.data), curr(sz) {}
    std::string &deref() const;
    StrBlobPtr &incr();

private:
    std::weak_ptr<std::vector<std::string>> wptr;
    StrBlob::size_type curr = 0;
    std::shared_ptr<std::vector<std::string>> check(StrBlob::size_type, const std::string &) const;
};
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(StrBlob::size_type i, const std::string &msg) const
{ // 检查 wptr 不是空悬指针，且 curr 没有超出 vector 的界，则返回 vector 的 shared_ptr 指针
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
std::string &StrBlobPtr::deref() const
{ // 返回 wptr 指向的 std::vector 中的第 curr 个元素的非常量引用。不改变指针 wptr 和计数器 curr, 因此是 const 函数
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
StrBlobPtr &StrBlobPtr::incr()
{ // 将计数器 curr 自增
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

// 最后再定义 StrBlob 中用到 StrBlobPtr 的两个函数
StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }