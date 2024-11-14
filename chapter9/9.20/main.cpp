// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <list>
#include <deque>
#include <iostream>
using std::cout;
using std::deque;
using std::endl;
using std::list;

int main()
{
    list<int> c1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> c2;
    deque<int> c3;
    for (auto i : c1)
    {
        if (i % 2 == 0)
            c2.push_back(i); // 偶数
        else
            c3.push_back(i); // 奇数
    }

    // 验证偶数和奇数分别放到不同的 deque 中
    for (auto i : c2)
    {
        cout << i << ' ';
    }
    cout << endl;
    for (auto i : c3)
    {
        cout << i << ' ';
    }
    cout << endl;
}