// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s = "ab2c3d7R4E6";
    string number = "0123456789";

    string::size_type pos1 = 0;
    while ((pos1 = s.find_first_of(number, pos1)) != string::npos)
    {
        cout << "found number at index: " << pos1 << " element is " << s[pos1] << endl;
        ++pos1;
    }
    cout << endl;
    string::size_type pos2 = 0;
    while ((pos2 = s.find_first_not_of(number, pos2)) != string::npos)
    {
        cout << "found letter at index: " << pos2 << " element is " << s[pos2] << endl;
        ++pos2;
    }
}