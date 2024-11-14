// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
    ifstream in("data.txt");
    vector<string> vec;
    while (in)
    {
        string str;
        in >> str;
        vec.push_back(str);
    }

    for (auto i : vec)
    {
        cout << i << ' ';
    }
}