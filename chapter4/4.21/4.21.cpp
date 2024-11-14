// Windows Powershell: g++ -std=c++11 -Wall -o 4.21.exe 4.21.cpp ; ./4.21.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 4.21.out 4.21.cpp ; ./4.21.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec = {3, 4, 5, 5, 7, 89, 34, 54, 68};
    for (auto &i : vec)
        i % 2 == 0 ?: i *= 2; // 如果是偶数的话就不用操作，因此 expr1 是空的。

    for (auto i : vec)
        cout << i << ' ';
    cout << endl;

    return 0;
}
