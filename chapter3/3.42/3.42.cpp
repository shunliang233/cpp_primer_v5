// Windows Powershell: g++ -std=c++11 -Wall -o 3.42.exe 3.42.cpp ; ./3.42.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.42.out 3.42.cpp ; ./3.42.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5};
    int ia[10] = {}; // 没法根据 vector 的长度来得到数组长度，只能设置一个可能足够长的数组。因为 vec.size() 的返回值不是 constexpr, 不能用作数组长度。
    for (int i = 0; i != vec.size(); i++)
        ia[i] = vec[i];

    for (auto i : ia)
        cout << i << endl;
    return 0;
}