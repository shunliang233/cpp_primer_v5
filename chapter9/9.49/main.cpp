// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main()
{
    const string ascender = "bdfhijkltABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string descender = "gjpqy";
    ifstream file("data.txt");
    string FindWord;

    string word;
    while (file >> word)
    {
        if (word.find_first_of(ascender) == string::npos && word.find_first_of(descender) == string::npos && word.size() > FindWord.size())
            FindWord = word;
    }

    cout << FindWord << endl;
}