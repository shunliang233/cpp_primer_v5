// Windows Powershell: g++ -std=c++11 -Wall -o 3.36.exe 3.36.cpp ; ./3.36.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.36.out 3.36.cpp ; ./3.36.out

#include <iostream>
#include <cstddef>
#include <iterator>
#include <vector>
using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main()
{
    // 用于比较的 array 和 vector
    const size_t a1_size = 5;
    const size_t a2_size = 5;
    int a1[a1_size] = {1, 2, 3, 4, 5};
    int a2[a2_size] = {1, 2, 3, 4, 5};
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5};

    // 比较 array
    if (end(a1) - begin(a1) == end(a2) - begin(a2))
    {
        int i = 0;
        while (i != end(a1) - begin(a1) && a1[i] == a2[i])
            i++;
        if (i == end(a1) - begin(a1))
            cout << "a1 == a2" << endl;
        else
            cout << "a1 != a2" << endl;
    }
    else
        cout << "a1 != a2" << endl;

    // 比较 vector
    if (v1.size() == v2.size())
    {
        int i = 0;
        while (i != v1.size() && v1[i] == v2[i])
            i++;
        if (i == v1.size())
            cout << "v1 == v2" << endl;
        else
            cout << "v1 != v2" << endl;
    }
    else
        cout << "v1 != v2" << endl;

    return 0;
}