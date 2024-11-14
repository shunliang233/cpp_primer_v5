// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <vector>
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::vector;

int main()
{
    vector<int> v1;
    list<int> v2;

    vector<int> temp(v2.begin(), v2.end());
    if (v1 == temp)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}