// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include <string>
#include <list>
using std::cin;
using std::cout;
using std::list;
using std::endl;
using std::string;

// 换成 list 容器后完全不用修改程序
int main()
{
    string word;
    list<string> c;
    while (cin >> word)
    {
        c.push_back(word);
    }

    for (auto i = c.cbegin(); i != c.cend(); ++i)
    {
        cout << *i << ' ';
    }
    cout << endl;
}
