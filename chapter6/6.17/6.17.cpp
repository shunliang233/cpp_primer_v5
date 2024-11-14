// Windows Powershell: g++ -std=c++11 -Wall -o 6.17.exe 6.17.cpp ; ./6.17.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 6.17.out 6.17.cpp ; ./6.17.out

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// 判断 string 中是否有大写字母
bool has_upper(const string &s)
{
    bool upper = false;
    for (auto c : s)
    {
        if (isupper(c))
        {
            upper = true;
            break;
        }
    }
    return upper;
}

// 改写原先的 string, 而不是得到一个新的 string
void to_lower(string &s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }
}

int main()
{
    string s = "Hello World!";
    cout << s << endl;
    cout << has_upper(s) << endl;
    to_lower(s);
    cout << s << endl;
    return 0;
}
