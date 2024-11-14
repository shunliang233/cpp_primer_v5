// Windows Powershell: g++ -std=c++11 -Wall -o 4.5.exe 4.5.cpp ; gc data.txt | ./4.5.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 4.5.out 4.5.cpp ; ./4.5.out < data.txt

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec; // 存储所有读入的整数
    int i = 0;       // 暂时存储当前读入的整数
    while (cin >> i && i != 42)  // 当读入合法且不为 42 时才存下来
        vec.push_back(i);

    for (auto i : vec)
        cout << i << ' ';
    cout << endl;

    return 0;
}