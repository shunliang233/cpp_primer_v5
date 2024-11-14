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
    vector<pair<int, string>> vec1;
    vector<pair<int, string>> vec2;
    vector<pair<int, string>> vec3;

    for (int j = 0; j != s.size() && j != i.size(); ++j)
    {
        // 感觉都差不多，可能第 3 个用构造函数的麻烦一点
        vec1.push_back({i[j], s[j]});
        vec2.push_back(make_pair(i[j], s[j]));
        vec3.push_back(pair<int, string>(i[j], s[j]));
    }
}