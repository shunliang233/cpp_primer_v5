// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp TextQuery.cpp query.cpp make_plural.cpp print.cpp runQueries.cpp ; ./main.out

#include <fstream>
#include "function_head.hpp"
using std::ifstream;

// 2024-03-22 v1
// 终于有点体会到编程的乐趣了
// 这是一个典型的多文件程序，原则就是：类的定义放在 hpp 文件中、类成员函数的定义放在 cpp 文件中、外部函数的声明放在 hpp 文件中、外部函数的定义放在 cpp 文件中
// 只有简单的类成员函数才会和类的定义一起放在 hpp 文件，像 TextQuery::query 这样的使用到其他类的复杂成员函数，一定是单独在一个 cpp 文件中定义的
// 所有的文件中仅包含必须的头文件，编译时只需要将所有 cpp 文件直接列出来在一起编译，或者分别编译再链接编译好的文件。
int main()
{
    ifstream file("data.txt");
    runQueries(file);
}