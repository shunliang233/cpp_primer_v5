// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <vector>
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::list;
using std::vector;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> c1;
    list<int> c2;
    for (auto i : ia)
    {
        c1.push_back(i);
        c2.push_back(i);
    }

    auto i1 = c1.begin();
    while (i1 != c1.end())
    {
        if (*i1 % 2)
            ++i1; // 奇数
        else
            i1 = c1.erase(i1); // 偶数
    }
    auto i2 = c2.begin();
    while (i2 != c2.end())
    {
        if (*i2 % 2)
            i2 = c2.erase(i2); // 奇数
        else
            ++i2; // 偶数
    }

    // 验证 list 中是偶数, vector 中是奇数
    for (auto i : c1)
        cout << i << ' ';
    cout << endl;
    for (auto i : c2)
        cout << i << ' ';
    cout << endl;
}