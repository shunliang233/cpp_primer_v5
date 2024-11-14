// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <fstream>
#include "StrBlob.hpp"
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main()
{
    // 将文本读入 StrBlob 对象中
    ifstream file("data.txt");
    StrBlob a;
    string word;
    while (file >> word)
    {
        a.push_back(word);
    }

    // 2024-11-01 既然发现 StrBlobPtr 实际上是迭代器，就可以使用迭代器的标准用法了
    for (auto it = a.begin(); !it.equal(a.end()); it.incr())
    {
        cout << it.deref() << ' ';
    }
    cout << endl;
}