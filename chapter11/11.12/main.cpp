// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

int main()
{
    vector<string> s = {"aa", "da", "dsf"};
    vector<int> i = {1, 34, 5};
    vector<pair<int, string>> vec;

    for (int j = 0; j != s.size() && j != i.size(); ++j)
    {
        vec.push_back({i[j], s[j]});
    }
}