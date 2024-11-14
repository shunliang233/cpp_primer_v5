// Windows Powershell: g++ -std=c++11 -Wall -o 5.19.exe 5.19.cpp ; ./5.19.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.19.out 5.19.cpp ; ./5.19.out

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    do
    {
        cout << "Pleas enter two strings: " << endl;
        string str1, str2;
        cin >> str1 >> str2;
        if (str1.size() > str2.size())
            cout << str2 << endl;
        else
            cout << str1 << endl;
    } while (cin);

    return 0;
}