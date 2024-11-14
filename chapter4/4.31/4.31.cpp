// Windows Powershell: g++ -std=c++11 -Wall -o 4.31.exe 4.31.cpp ; ./4.31.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 4.31.out 4.31.cpp ; ./4.31.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec = {2, 44, 34, 43, 65, 79, 56, 3, 57};
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;

    // 输出 vector
    for (auto i : ivec)
        cout << i << ' ';
    cout << endl;

    return 0;
}