// Windows Powershell: g++ -std=c++11 -Wall -o 5.3.exe 5.3.cpp ; ./5.3.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.3.out 5.3.cpp ; ./5.3.out

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;
    return 0;
}