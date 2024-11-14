#pragma once
#include <vector>
#include <string>
#include <stdexcept>
using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::runtime_error;
using std::shared_ptr;
using std::size_t;
using std::string;
using std::vector;
using std::weak_ptr;

// 2024-03-20 v1
// 由于在 StrBlob 类的成员函数中要用到 StrBlobPtr 的构造函数，在 StrBlobPtr 类的构造函数中要用到 StrBlob 的成员 data
// 因此完整定义任意一个类都需要另一个类已经完整定义，不可能将两个类分别存储在不同的文件中，而且头文件互相包含也是被禁止的
// 既然是 StrBlob 的成员函数 begin 和 end 的函数体定义中才需要 StrBlobPtr 的构造函数，就可以先声明这两个函数，等 StrBlobPtr 定义完毕后，再定义这两个函数
// 需要先前置声明 StrBlobPtr 类，友元声明无法代替前置声明
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;
    StrBlob() = default;
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)){};
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;
    StrBlobPtr begin(); // 不能使用 StrBlobPtr 类型中的内容
    StrBlobPtr end();

private:
    shared_ptr<vector<string>> data = make_shared<vector<string>>(); // 默认初始化为空 shared_ptr 指针，空悬指针是不能解引用的，因此要在类内初始化分配为非空悬指针
    void check(size_type i, const string &msg) const;
};
void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

class StrBlobPtr
{
public:
    StrBlobPtr() = default;
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incr();

private:
    weak_ptr<vector<string>> wptr; // 默认初始化为空 wear_ptr, 此时是空悬指针
    size_t curr = 0;
    shared_ptr<vector<string>> check(size_t, const string &) const;
};
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{ // 检查 wptr 不是空悬指针，且 curr 没有超出 vector 的界，则返回 vector 的 shared_ptr 指针
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}
string &StrBlobPtr::deref() const
{ // 返回 wptr 指向的 vector 中的第 curr 个元素的非常量引用。不改变指针 wptr 和计数器 curr, 因此是 const 函数
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