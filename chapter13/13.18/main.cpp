// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// 拷贝构造和拷贝赋值需要保证每个 Employee 的 mysn 都不一样并且不变
class Employee
{
public:
    Employee() : mysn(++count) {}                                // 默认构造函数，新生成唯一的 mysn
    Employee(const string &s) : mysn(++count), name(s) {}        // 提供姓名的构造函数，新生成唯一的 mysn
    Employee(const Employee &a) : mysn(++count), name(a.name) {} // 拷贝构造函数，使用新生成的 mysn 而不是从 a 中拷贝来
    Employee &operator=(const Employee &a);                      // 拷贝赋值运算符

    const int mysn; // 身份证号不能变
    string name;

private:
    static int count;
};

int Employee::count = 0;

// 拷贝赋值运算符，不用生成新的 mysn, 使用被拷贝对象原有的 mysn
// 但是不能使用合成的拷贝赋值运算符，因为成员变量中有 const
Employee &Employee::operator=(const Employee &a)
{
    name = a.name;
    return *this;
}

void f(const Employee &s) { cout << s.mysn << endl; }

// 不会拷贝 a 中的 mysn 到 b 和 c 中，调用 f 函数时不发生拷贝，因此输出的是 a, b, c 各自的 mysn (这种情况是最合理的)
int main()
{
    Employee a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}