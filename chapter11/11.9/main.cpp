// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <map>
#include <list>
#include <string>
using std::cout;
using std::endl;
using std::list;
using std::map;
using std::string;

int main()
{
    // 关键字为单词
    // 值为单词出现的行号列表
    map<string, list<int>> imap = {{"the", {1, 34, 65}}, {"a", {3, 4, 54}}};
}