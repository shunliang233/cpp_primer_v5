// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v1;
    vector<int> v2;

    if (v1 == v2)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}