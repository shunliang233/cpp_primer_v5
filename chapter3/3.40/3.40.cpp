// Windows Powershell: g++ -std=c++11 -Wall -o 3.40.exe 3.40.cpp ; ./3.40.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 3.40.out 3.40.cpp ; ./3.40.out

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

int main()
{
    const char c1[] = "abcd";
    const char c2[] = "efgh";
    char c3[10] = {};
    strcpy(c3, c1);
    strcat(c3, c2);
    for (auto i : c3)
        cout << i << endl;
    return 0;
}