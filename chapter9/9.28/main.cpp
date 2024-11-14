// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe data1.txt data2.txt data3.txt
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out data1.txt data2.txt data3.txt

#include <iostream>
#include <forward_list>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::forward_list;
using std::ifstream;
using std::string;
using std::vector;

// 容器需要传引用调用，这样才能将形参的修改应用到实参上
void hhhh(forward_list<string> &list, const string &s1, const string &s2)
{
    auto prev = list.before_begin();
    auto curr = list.begin();
    // 要在 curr 之后插入，看起来不需要使用 prev 迭代器
    // 最晚要在尾元素后插入，因此等 curr == list.end() 到达尾后迭代器时就晚了
    // 不能使用 --curr 退回到尾元素迭代器，也不能 curr + 1 获得一个临时迭代器，这是 vector 和 string 的迭代器才有的运算
    // 解决办法是使用 prev 迭代器，或者在 ++curr 前将其备份（实际上每次 ++curr 前都要备份，就跟用 prev 几乎一样了）
    while (curr != list.end())
    {
        // 如果找到了 s1, 就啥也不用管，在后面插入 s2 之后就退出
        if (*curr == s1)
        {
            list.insert_after(curr, s2);
            break;
        }
        // 如果没找到，就向下移动
        else
        {
            ++curr;
            ++prev;
        }

        // 如果到尾后迭代器了，就在尾部添加 s2, 然后直接退出
        if (curr == list.end())
        {
            list.insert_after(prev, s2);
            break;
        }
    }
}

int main(int argc, char **argv)
{
    // 测试三种情况
    string word;
    vector<string> vec;
    cout << endl;

    // s1 位于中间
    vec.clear();
    ifstream file1(argv[1]);
    forward_list<string> list1;
    while (file1 >> word)
    {
        vec.push_back(word);
    }
    list1.insert_after(list1.before_begin(), vec.begin(), vec.end());
    hhhh(list1, "aaaa", "hhhh");
    for (auto i : list1)
        cout << i << ' ';
    cout << endl
         << endl;

    // s1 位于末尾
    vec.clear();
    ifstream file2(argv[2]);
    forward_list<string> list2;
    while (file2 >> word)
    {
        vec.push_back(word);
    }
    list2.insert_after(list2.before_begin(), vec.begin(), vec.end());
    hhhh(list2, "aaaa", "hhhh");
    for (auto i : list2)
        cout << i << ' ';
    cout << endl
         << endl;

    // s1 不存在
    vec.clear();
    ifstream file3(argv[3]);
    forward_list<string> list3;
    while (file3 >> word)
    {
        vec.push_back(word);
    }
    list3.insert_after(list3.before_begin(), vec.begin(), vec.end());
    hhhh(list3, "aaaa", "hhhh");
    for (auto i : list3)
        cout << i << ' ';
    cout << endl
         << endl;
}