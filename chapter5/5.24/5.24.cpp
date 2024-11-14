// Windows Powershell: g++ -std=c++11 -Wall -o 5.24.exe 5.24.cpp ; ./5.24.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.24.out 5.24.cpp ; ./5.24.out

#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int a, b;
    cin >> a >> b;
    if (b == 0)
        throw runtime_error("The second number can not be 0.");
    cout << a / b << endl;

    return 0;
}