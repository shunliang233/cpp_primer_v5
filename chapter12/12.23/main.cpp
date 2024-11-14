// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::unique_ptr;

int main()
{
    const size_t up_size = 10;
    char a1[up_size] = "abcd";
    char a2[] = "efgh";
    strcat(a1, a2); // 将 a2 连接到 a1 的尾部，程序员负责保证 a1 足够长
    unique_ptr<char[]> up(new char[up_size]);
    size_t count = 0;
    for (auto i : a1)
    {
        if (count != up_size)
        {
            up[count++] = i;
        }
    }
    for (auto i = 0; i != up_size; ++i)
    {
        cout << up[i] << endl;
    }
    // 连接两个标准库 string 对象就不做了，太简单了
}