// Windows Powershell: g++ -std=c++11 -Wall -o 5.17.exe 5.17.cpp ; ./5.17.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.17.out 5.17.cpp ; ./5.17.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec1 = {0, 1, 1, 2};
    vector<int> vec2 = {0, 1, 1, 2, 3, 5, 8};

    // 找到短 vector 的长度
    decltype(vec1.size()) size = 0;
    if (vec1.size() < vec2.size())
        size = vec1.size();
    else
        size = vec2.size();

    // 循环结束后，如果各项相等直到末尾则为 true.
    decltype(vec1.size()) i = 0;
    for (; i != size && vec1[i] == vec2[i]; ++i)
        ;
    if (i == size)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}