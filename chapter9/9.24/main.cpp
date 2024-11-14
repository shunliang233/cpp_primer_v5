// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5};

    cout << v.at(0) << endl;
    cout << v[0] << endl;
    cout << v.front() << endl;
    cout << *v.cbegin() << endl;
}