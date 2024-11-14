// Windows Powershell: g++ -std=c++11 -Wall -o 3.8.exe 3.8.cpp ; ./3.8.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.8.out 3.8.cpp ; ./3.8.out

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 将所有字符都换成 X
int main()
{
    // 用 while 实现
    string str1 = "Your hex number";
    string::size_type n1 = 0;
    while (n1 < str1.size())
    {
        str1[n1] = 'X';
        n1++;
    }
    cout << str1 << endl;

    // 用 for 实现
    string str2 = "Your hex number";
    for (string::size_type n2 = 0; n2 < str2.size(); n2++)
        str2[n2] = 'X';
    cout << str2 << endl;

    return 0;
}