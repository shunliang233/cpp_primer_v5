// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<int, string> imap = {{1, "aaa"}, {2, "bbb"}};
    auto map_it = imap.begin();
    map_it->second = "ccc";
}