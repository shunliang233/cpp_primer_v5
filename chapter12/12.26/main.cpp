// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
using std::allocator;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// 用 allocate 确实要比 new 好很多，将分配内存和构造元素区分开来，使得程序的逻辑也更清晰更易理解了
int main()
{
    // 分配内存
    const size_t n = 100;
    ifstream file("data.txt");
    allocator<string> a;
    auto const p = a.allocate(n); // 分配的内存的首元素指针
    auto q = p;                   // 最后构造的元素之后位置的指针

    // 构造元素
    string word;
    while (file >> word && q != p + n)
    {
        a.construct(q++, word);
    }

    // 读取内存
    for (auto x = p; x != q; ++x)
    {
        cout << *x << ' ';
    }
    cout << endl;
}