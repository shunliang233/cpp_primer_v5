// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp HasPtr_v7_1.cpp HasPtr_v7_2.cpp ; ./main.out

#include <iostream>
#include <chrono>
#include "HasPtr_v7_1.hpp"
#include "HasPtr_v7_2.hpp"
using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::high_resolution_clock;

// 2024-11-10 v7
// 定义移动构造函数和移动赋值运算符
// v7_2 版本分别定义拷贝赋值运算符和移动赋值运算符，而 v7_1 版本利用 swap 函数一起定义
// v7_2 会稍快一点，因为 v7_1 在赋值时会多定义一个临时 HasPtr 变量

int main()
{
    int n = 1000000;

    // v1
    auto start_v1 = high_resolution_clock::now();
    for (int i = 0; i != n; ++i)
    {
        HasPtr_v7_1 a("abc");
        HasPtr_v7_1 b;
        b = std::move(a);
    }
    auto end_v1 = high_resolution_clock::now();

    // v2
    auto start_v2 = high_resolution_clock::now();
    for (int i = 0; i != n; ++i)
    {
        HasPtr_v7_2 a("abc");
        HasPtr_v7_2 b;
        b = std::move(a);
    }
    auto end_v2 = high_resolution_clock::now();

    // 比较时间
    duration<double> duration_v1 = end_v1 - start_v1;
    duration<double> duration_v2 = end_v2 - start_v2;
    cout << "v1: " << duration_v1.count() << " 秒" << endl;
    cout << "v2: " << duration_v2.count() << " 秒" << endl;
}