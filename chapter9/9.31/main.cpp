// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <list>
#include <forward_list>
using std::cout;
using std::endl;
using std::forward_list;
using std::list;

int main()
{
    // list
    list<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter1 = v1.begin();
    while (iter1 != v1.end())
    {
        if (*iter1 % 2)
        {
            iter1 = v1.insert(iter1, *iter1); // 在前面插入相同元素
            ++ ++iter1;
        }
        else
        {
            iter1 = v1.erase(iter1);
        }
    }
    for (auto i : v1)
        cout << i << ' ';
    cout << endl;

    // forward_list
    forward_list<int> v2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev2 = v2.before_begin();
    auto iter2 = v2.begin();
    while (iter2 != v2.end())
    {
        if (*iter2 % 2)
        {
            iter2 = v2.insert_after(iter2, *iter2); // 在后面插入相同元素
            ++iter2;
            ++ ++prev2; // prev2 没有重新赋值，但不用担心失效问题
        }
        else
        {
            iter2 = v2.erase_after(prev2); // iter2 被删掉了，因此要重新赋值为下一个元素，而 prev2 不用变
        }
    }
    for (auto i : v2)
        cout << i << ' ';
    cout << endl;
}