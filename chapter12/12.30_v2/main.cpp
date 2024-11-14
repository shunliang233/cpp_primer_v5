// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp TextQuery.cpp QueryResult.cpp ; ./main.out

#include <iostream>
#include <fstream>
#include "TextQuery.hpp"
#include "QueryResult.hpp"
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

// 2024-11-02 v2

// 多文件程序原则就是：接口放在 hpp 文件中，实现放在 cpp 文件中
// 接口：类的声明和定义、类成员函数的声明、外部函数的声明
// 实现：类成员函数的定义、外部函数的定义

// 所有的文件中仅包含用到的接口所在的头文件。
// 编译时只需要将所有 cpp 文件直接列出来在一起编译，或者分别编译再链接编译好的文件。

// 主要是接口和实现要分别放在 hpp 和 cpp 文件中，其他规则都不重要。
// 类成员函数和与类相关的外部函数可以定义在同一个 cpp 文件中，也可以定义在各自的 cpp 文件中。
// 这个主要是看代码量，如果实现代码不多的话，都放在 hpp 同名的 cpp 文件中即可。

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream file("data.txt");
    runQueries(file);
    
}