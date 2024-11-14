// Windows Powershell: g++ -std=c++11 -Wall -o 3.39.exe 3.39.cpp ; ./3.39.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.39.out 3.39.cpp ; ./3.39.out

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1 = "abcd";
    string s2 = "abcd";
    const char c1[] = "abcde";
    const char c2[] = "abcde";

    // 比较 string 字符串
    if (s1 < s2)
        cout << "s1 < s2" << endl;
    else if (s1 == s2)
        cout << "s1 == s2" << endl;
    else
        cout << "s1 > s2" << endl;

    // 比较 C 风格字符串
    if (strcmp(c1, c2) < 0)
        cout << "c1 < c2" << endl;
    else if (strcmp(c1, c2) == 0)
        cout << "c1 == c2" << endl;
    else
        cout << "c1 > c2" << endl;

    return 0;
}
