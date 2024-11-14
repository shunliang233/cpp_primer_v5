// Windows Powershell: g++ -std=c++11 -Wall -o 3.6.exe 3.6.cpp ; ./3.6.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.6.out 3.6.cpp ; ./3.6.out

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 将所有字符都换成 X
int main()
{
    string str = "Your hex number";
    for(auto &c : str)
    {
        c = 'X';
    }
    cout << str << endl;
    return 0;
}
