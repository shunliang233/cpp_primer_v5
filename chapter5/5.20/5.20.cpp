// Windows Powershell: g++ -std=c++11 -Wall -o 5.20.exe 5.20.cpp ; gc data.txt | ./5.20.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.20.out 5.20.cpp ; ./5.20.out < data.txt

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str1;
    string str2;
    while (cin >> str2)
    {
        if (str2 == str1)
        {
            cout << str1 << endl;
            break;
        }
        str1 = str2;
    }

    // 如果 while 通过 break 结束，则 cin 的状态一定为 true, 即使已经将 cin 中最后一个单词存入 str2.
    // 如果 while 自然结束，则 cin 的状态一定为 false.
    // 结论: cin 的当前状态与最后一次 cin >> str2 的状态相同.
    if (!cin)
        cout << "No continue word." << endl;

    return 0;
}