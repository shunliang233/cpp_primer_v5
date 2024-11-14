#include <vector>
#include <string>
#include <memory>
#include "StrBlob.hpp"
using std::make_shared;
using std::string;
using std::vector;

// StrBlob 的成员函数
inline StrBlob &StrBlob::operator=(const StrBlob &s)
{
    data = make_shared<vector<string>>(*s.data);
    return *this;
}

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

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

// StrBlobPtr 的成员函数
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

bool StrBlobPtr::equal(const StrBlobPtr &that) const
{ // 比较两个 StrBlobPtr 是否相同
    // 类的成员函数可以访问同类对象的私有成员，这是因为私有成员的访问权限是基于类而不是对象的
    if (!this->wptr.owner_before(that.wptr) && !that.wptr.owner_before(this->wptr) && this->curr == that.curr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ConstStrBlobPtr 的成员函数
std::shared_ptr<const std::vector<std::string>> ConstStrBlobPtr::check(StrBlob::size_type i, const std::string &msg) const
{ // 检查 wptr 不是空悬指针，且 curr 没有超出 vector 的界，则返回 vector 的 shared_ptr 指针
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

const std::string &ConstStrBlobPtr::deref() const
{ // 返回 wptr 指向的 vector 中的第 curr 个元素的非常量引用。不改变指针 wptr 和计数器 curr, 因此是 const 函数
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{ // 将计数器 curr 自增
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}