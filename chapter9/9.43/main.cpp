// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::istringstream;
using std::string;

// 懒得查找 oldVal 的位置了，直接重写 string 了
void change(string &s, const string &oldVal, const string &newVal)
{
    istringstream is(s);
    string word;
    string NewString;
    while (is >> word)
    {
        if (word == oldVal)
        {
            NewString += newVal;
        }
        else
        {
            NewString += word;
        }
        NewString.push_back(' ');
    }
    NewString.erase(NewString.size() - 1); // 删掉最后一个多加的空格
    s = NewString;
}

int main()
{
    string s1 = "I tho though my tho hhh though.";
    cout << s1 << endl;
    change(s1, "tho", "though");
    cout << s1 << endl;
    cout << endl;

    string s2 = "I thru through my thru hhh through.";
    cout << s2 << endl;
    change(s2, "thru", "through");
    cout << s2 << endl;
}