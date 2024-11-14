// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

istream &read(istream &is)
{
    while (!is.eof())
    {
        string word;
        is >> word;
        cout << word << " ";
    }

    cout << endl
         << "Before clear: " << is.eof() << is.fail() << is.bad() << is.good();
    is.clear();
    return is;
}

int main()
{
    istream &aaa = read(cin);
    cout << endl
         << "After clear: "
         << aaa.eof() << aaa.fail() << aaa.bad() << aaa.good();
}