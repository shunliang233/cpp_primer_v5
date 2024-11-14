// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;

bool five(const string &s)
{
    return s.size() >= 5;
}

int main()
{
    // 读取单词并写入 vector
    istringstream is("the quick red fox jumps over the slow red turtle");
    vector<string> vec;
    string word;
    while (is >> word)
        vec.push_back(word);

    // partition 分类，并输出前半部分
    auto TrueEnd = partition(vec.begin(), vec.end(), five);
    for (auto i = vec.begin(); i != TrueEnd; ++i)
    {
        cout << *i << endl;
    }
}