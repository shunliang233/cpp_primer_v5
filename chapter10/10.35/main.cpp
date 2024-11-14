// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec = {1, 2, 42, 43, 6, 443, 42, 435, 65, 765, 8, 42};
    if (vec.cbegin() != vec.cend())
    {
        auto it = vec.cend();
        do
        {
            --it;
            cout << *it << endl;
        } while (it != vec.cbegin());
    }
}