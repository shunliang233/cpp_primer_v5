// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::unique_ptr;

int main()
{
    // 先读入字符串，判断长度后再创建动态分配的字符数组
    ifstream file("data.txt");
    string line;
    getline(file, line);

    unique_ptr<char[]> up(new char[line.size()]);
    for (size_t i = 0; i != line.size(); ++i)
    {
        up[i] = line[i];
    }

    for (size_t i = 0; i != line.size(); ++i)
    {
        cout << up[i];
    }
    cout << endl;
}