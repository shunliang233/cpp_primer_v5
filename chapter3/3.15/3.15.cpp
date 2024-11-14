// Windows Powershell: g++ -std=c++11 -Wall -o 3.15.exe 3.15.cpp ; gc data.txt | ./3.15.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.15.out 3.15.cpp ; ./3.15.out < data.txt

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// 读入一组字符串，并存入 vector 对象
int main()
{
    string i;
    vector<string> vec;
    while (cin >> i)
        vec.push_back(i);
    cout << vec.size() << endl;
    return 0;
}