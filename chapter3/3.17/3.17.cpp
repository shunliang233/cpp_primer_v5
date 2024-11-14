// Windows Powershell: g++ -std=c++11 -Wall -o 3.17.exe 3.17.cpp ; gc data.txt | ./3.17.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.17.out 3.17.cpp ; ./3.17.out < data.txt

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string word;
    vector<string> vec;

    // 将单词读入 vec 中
    while (cin >> word)
    {
        for (auto &c : word)
        {
            c = toupper(c);
        }
        vec.push_back(word);
    }

    // 输出 vec 中的单词
    for (auto str : vec)
    {
        cout << str << endl;
    }

    return 0;
}