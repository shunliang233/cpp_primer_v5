// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <vector>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 直接调用构造函数肯定是不行的，还是一个一个 push_back 吧。
int main()
{
    vector<char> vec = {'H', 'e', 'l', 'l', 'o'};
    string s;
    for (auto i : vec)
        s.push_back(i);

    cout << s << endl;
}