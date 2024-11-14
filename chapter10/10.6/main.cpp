// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec = {1, 2, 42, 43, 6, 443, 42, 435, 65, 765, 8, 42};
    fill_n(vec.begin(), vec.size(), 0);
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
}