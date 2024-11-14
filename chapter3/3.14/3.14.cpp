// Windows Powershell: g++ -std=c++11 -Wall -o 3.14.exe 3.14.cpp ; gc data.txt | ./3.14.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.14.out 3.14.cpp ; ./3.14.out < data.txt

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// 读入一组整数，并存入 vector 对象
int main()
{
    int i = 0;
    vector<int> vec;
    while (cin >> i)
        vec.push_back(i);
    cout << vec.size() << endl;
    return 0;
}