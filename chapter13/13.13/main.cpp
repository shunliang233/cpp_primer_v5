// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <string>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::vector;

struct X
{
    X() { cout << "X()" << endl; }                     // 默认构造函数
    X(const X &a) { cout << "X(const X &a)" << endl; } // 拷贝构造函数
    X &operator=(const X &a)
    {
        cout << "X &operator=(const X &a)" << endl;
        return *this;
    }                                // 拷贝赋值运算符
    ~X() { cout << "~X()" << endl; } // 析构函数
};

// 涉及到 vector 时会比预期多一次拷贝构造和析构，看起来就像多了个临时对象一样
int main()
{
    X a;               // 调用 1 次默认构造函数
    X *b = new X(a);   // new 调用 1 次匹配的构造函数（正好就是拷贝构造函数）
    X c;               // 调用 1 次默认构造函数
    vector<X> d = {a}; // 调用 2 次拷贝构造函数和 1 次析构函数。因为列表中的 a 会先被用于拷贝构造一个临时对象，再拷贝构造给 vector，表达式结束后会调用临时对象的析构函数
    X e = a;           // 调用 1 此拷贝构造函数
    delete b;          // 调用 1 次析构函数
    e = c;             // 调用 1 次拷贝赋值运算符
    d.push_back(e);    // 调用 2 次拷贝构造函数和 1 次析构函数
    // 销毁 a, c, d[0], d[1], e 一共 5 个析构函数
}