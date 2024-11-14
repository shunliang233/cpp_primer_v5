// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp HasPtr.cpp ; ./main.out

#include <iostream>
#include <chrono>
#include "HasPtr.hpp"
#include "HasPtr.hpp"
using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::high_resolution_clock;

// 2024-11-10 v7_3
// 定义两个移动赋值运算符
// 虽然使用 swap 的版本多了一层隐式调用移动构造函数，但都是精确匹配，所以导致重载问题

int main()
{
    int n = 1000000;

    // v1
    auto start_v1 = high_resolution_clock::now();
    for (int i = 0; i != n; ++i)
    {
        HasPtr a("abc");
        HasPtr b;
        b = std::move(a);
    }
    auto end_v1 = high_resolution_clock::now();

    // 比较时间
    duration<double> duration_v1 = end_v1 - start_v1;
    cout << "v1: " << duration_v1.count() << " 秒" << endl;
}