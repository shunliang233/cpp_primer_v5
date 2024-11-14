// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include "HasPtr_v4.hpp"
#include "HasPtr_v5.hpp"
#include <chrono>
#include <iostream>
using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::high_resolution_clock;

int main()
{
    using std::swap;
    int n = 1000000;

    // v4
    auto start_v4 = high_resolution_clock::now();
    for (int i = 0; i != n; ++i)
    {
        HasPtr_v4 a("aaa");
        HasPtr_v4 b;
        swap(a, b);
    }
    auto end_v4 = high_resolution_clock::now();

    // v5

    auto start_v5 = high_resolution_clock::now();
    for (int i = 0; i != n; ++i)
    {
        HasPtr a("aaa");
        HasPtr b;
        swap(a, b);
    }
    auto end_v5 = high_resolution_clock::now();

    // 比较时间
    duration<double> duration_v4 = end_v4 - start_v4;
    duration<double> duration_v5 = end_v5 - start_v5;
    cout << "v4: " << duration_v4.count() << " 秒" << endl;
    cout << "v5: " << duration_v5.count() << " 秒" << endl;
}