// Windows Powershell: g++ -std=c++11 -Wall -o 3.24.exe 3.24.cpp ; gc data.txt | ./3.24.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.24.out 3.24.cpp ; ./3.24.out < data.txt

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    // 读取一组整数
    int i = 0;
    vector<int> vec;
    while (cin >> i)
        vec.push_back(i);

    // 输出相邻整数的和
    cout << "相邻整数的和：" << endl;
    for (auto it = vec.cbegin(); it != vec.cend() - 1; it++)
    {
        cout << *it + *(it + 1) << ' ';
    }
    cout << endl;

    // 输出正数和倒数的和
    cout << "正数和倒数的和：" << endl;
    for (auto it = vec.cbegin(); it != vec.cbegin() + (vec.cend() - vec.cbegin()) / 2; it++)
    {
        cout << *it + *(vec.cend() - (it - vec.cbegin()) - 1) << ' ';
    }
    cout << endl;

    return 0;
}