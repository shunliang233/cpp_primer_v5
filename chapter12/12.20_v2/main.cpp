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

    // 突然想起来应该可以利用 StrBlob 中的 begin 和 end 函数来获取 StrBlobPtr 对象
    auto b = a.begin();
    while (1)
    {
        try
        {
            cout << b.deref() << ' ';
            b.incr();
        }
        catch (std::runtime_error err)
        {
            break;
        }
        catch (std::out_of_range err)
        {
            break;
        }
    }
    cout << endl;
}