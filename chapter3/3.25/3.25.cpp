// Windows Powershell: g++ -std=c++11 -Wall -o 3.25.exe 3.25.cpp ; gc data.txt | ./3.25.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.25.out 3.25.cpp ; ./3.25.out < data.txt

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    // 初始化
    vector<int> scores(11, 0);
    auto beg = scores.begin();
    int grade = 0;

    // 统计成绩
    while (cin >> grade)
    {
        if (grade <= 100)
            ++(*(beg + grade / 10));
    }

    // 输出统计结果
    for (auto it = scores.cbegin(); it != scores.cend(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}