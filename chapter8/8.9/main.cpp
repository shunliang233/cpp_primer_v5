// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::istream;
using std::istringstream;
using std::string;

istream &read(istream &is)
{
    string word;
    while (is >> word)
    {
        cout << word << ' ';
    }

    is.clear(is.rdstate() & ~is.eofbit);
    return is;
}

// 在 macOS 的 oh-my-zsh 中，终端末尾的 % 表示 C++ 程序输出的最后没有换行，但是 shell 自动添加了换行符。
int main()
{
    string s = "lee 6095550132 2015550175 8005550000";
    istringstream record(s);
    read(record);
}