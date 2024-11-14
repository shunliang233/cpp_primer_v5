// Windows Powershell: g++ -std=c++11 -Wall -o 3.10.exe 3.10.cpp ; ./3.10.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.10.out 3.10.cpp ; ./3.10.out

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 去除字符串中的标点符号
int main()
{
    string str = "You hex number is: C05F0F.";
    string new_str;
    for (auto &c : str)
    {
        if (!ispunct(c))
            new_str += c;
    }
    cout << new_str << endl;
    return 0;
}