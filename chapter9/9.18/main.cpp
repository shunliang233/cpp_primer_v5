// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; gc data.txt | ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out < data.txt

#include <iostream>
#include <string>
#include <deque>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::string;

int main()
{
    string word;
    deque<string> c;
    while (cin >> word)
    {
        c.push_back(word);
    }

    for (auto i = c.cbegin(); i != c.cend(); ++i)
    {
        cout << *i << ' ';
    }
    cout << endl;
}
