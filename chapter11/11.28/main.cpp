// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <vector>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<int>> imap = {{"aaa", {1, 2, 3}}, {"vvd", {32, 456, 4}}};
    map<string, vector<int>>::iterator it;
    it = imap.find("aaa");
}