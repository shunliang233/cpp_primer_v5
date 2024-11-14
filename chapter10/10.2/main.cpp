// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
    const string val = "ss";
    list<string> vec = {"ss", "ds", "dss", "sn", "ss", "fd", "sss", "ds", "gv", "d", "dsd"};
    cout << count(vec.cbegin(), vec.cend(), val) << endl;
}