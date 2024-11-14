// Windows Powershell: g++ -std=c++11 -Wall -o 5.25.exe 5.25.cpp ; ./5.25.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.25.out 5.25.cpp ; ./5.25.out

#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw runtime_error("The second number can not be 0.");
            cout << a / b << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << "\nTry Again? Enter y or n:" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}