// Windows Powershell: g++ -std=c++11 -Wall -o 3.21.exe 3.21.cpp ; ./3.21.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.21.out 3.21.cpp ; ./3.21.out

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    // 3.13 题中的 vector
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    // vector 的容量和内容
    cout << "v1: size=" << v1.size() << ' ';
    for (auto i = v1.begin(); i != v1.end(); i++)
        cout << *i << ' ';
    cout << endl;

    cout << "v2: size=" << v2.size() << ' ';
    for (auto i = v2.begin(); i != v2.end(); i++)
        cout << *i << ' ';
    cout << endl;

    cout << "v3: size=" << v3.size() << ' ';
    for (auto i = v3.begin(); i != v3.end(); i++)
        cout << *i << ' ';
    cout << endl;

    cout << "v4: size=" << v4.size() << ' ';
    for (auto i = v4.begin(); i != v4.end(); i++)
        cout << *i << ' ';
    cout << endl;

    cout << "v5: size=" << v5.size() << ' ';
    for (auto i = v5.begin(); i != v5.end(); i++)
        cout << *i << ' ';
    cout << endl;

    cout << "v6: size=" << v6.size() << ' ';
    for (auto i = v6.begin(); i != v6.end(); i++)
        cout << *i << ' ';
    cout << endl;

    cout << "v7: size=" << v7.size() << ' ';
    for (auto i = v7.begin(); i != v7.end(); i++)
        cout << *i << ' ';
    cout << endl;

    return 0;
}
