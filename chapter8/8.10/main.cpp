// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main()
{
    // 将文件中的数据读入 vector 中
    ifstream file("data.txt");
    vector<string> vec;
    string line;
    while (getline(file, line))
    {
        vec.push_back(line);
    }

    // 将每个单词读到 word 对象中
    for (auto s : vec)
    {
        istringstream line(s);
        string word;
        while (line >> word)
        {
            cout << word << ' ';
        }
    }
}