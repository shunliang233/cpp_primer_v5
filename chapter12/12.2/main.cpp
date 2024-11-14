// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using std::cout;
using std::endl;
using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::shared_ptr;
using std::string;
using std::vector;

class StrBlob
{
public:
    // 类型别名
    typedef vector<string>::size_type size_type;

    // 构造函数
    StrBlob() = default;
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {};

    // 不需要调用 check 的函数
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }

    // 需要调用 check 的函数
    void pop_back();
    void do_front() const { check(0, "front on empty StrBlob"); };
    string &front();
    const string &front() const;
    void do_back() const { check(0, "back on empty StrBlob"); };
    string &back();
    const string &back() const;

private:
    shared_ptr<vector<string>> data = make_shared<vector<string>>(); // 默认初始化为空 shared_ptr 指针，空悬指针是不能解引用的，因此要在类内初始化分配为非空悬指针
    void check(size_type i, const string &msg) const;
};

// 定义成员函数
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

// 可以用 do_front 和 do_back 来完成实际任务（见 P248 的建议）
// front 函数必须返回 string & 或 const string &, 该返回值不能从 do_front 中获取，因为 do_front 函数不可能在返回 string & 和 const string & 之间自动转换
// 在 P248 的例子中, display 函数的返回值是从其自身获取的，并不是从 do_display 获取的
// 说明在这里，只有 check 函数可以写到 do_front 中，而 return data->front() 语句仍然得写在 front 函数中
// 如果没有扩展或调试需求的话，就不需要定义 do_front 和 do_back 函数了
string &StrBlob::front()
{
    do_front();
    return data->front();
}
const string &StrBlob::front() const
{
    do_front();
    return data->front();
}
string &StrBlob::back()
{
    do_back();
    return data->back();
}
const string &StrBlob::back() const
{
    do_back();
    return data->back();
}

int main()
{
    StrBlob a = {"aa", "bb"};
    const StrBlob b = {"11", "22", "33"};
    cout << a.front() << endl;
    cout << b.back() << endl;
}