// Windows Powershell: g++ -std=c++11 -Wall -o 3.20.exe 3.20.cpp ; gc data.txt | ./3.20.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.20.out 3.20.cpp ; ./3.20.out < data.txt

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
    for (int i = 0; i < vec.size() - 1; i++)  // 不是遍历所有元素，所以没法用范围 for 循环
    {
        cout << vec[i] + vec[i + 1] << ' ';
    }
    cout << endl;

    // 输出正数和倒数的和（个数为奇数时中间的不输出）
    cout << "正数和倒数的和：" << endl;
    for (int i = 0; i < vec.size() / 2; i++)
    {
        cout << vec[i] + vec[vec.size() - i - 1] << ' ';
    }
    cout << endl;

    return 0;
} 