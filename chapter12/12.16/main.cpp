// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
using std::unique_ptr;

// 报错: object of type 'unique_ptr<int>' cannot be assigned because its copy assignment operator is implicitly deleted
// 说明 macOS 上的编译器能给出易于理解的错误信息
int main()
{
    unique_ptr<int> a(new int(42));
    unique_ptr<int> b;
    b = a;
}