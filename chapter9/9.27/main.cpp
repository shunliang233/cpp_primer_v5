// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <forward_list>
using std::cout;
using std::endl;
using std::forward_list;

int main()
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else
        {
            ++prev;
            ++curr;
        }
    }

    // 验证 forward_list 中只剩下偶数
    for (auto i : flst)
    {
        cout << i << ' ';
    }
    cout << endl;
}