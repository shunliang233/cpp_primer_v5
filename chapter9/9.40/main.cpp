// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
    string word;

    ifstream file256("data256.txt");
    vector<string> svec256;
    svec256.reserve(1024);
    while (file256 >> word)
    {
        svec256.push_back(word);
    }
    svec256.resize(svec256.size() + svec256.size() / 2);
    cout << svec256.capacity() << endl;

    ifstream file512("data512.txt");
    vector<string> svec512;
    svec512.reserve(1024);
    while (file512 >> word)
    {
        svec512.push_back(word);
    }
    svec512.resize(svec512.size() + svec512.size() / 2);
    cout << svec512.capacity() << endl;

    ifstream file1000("data1000.txt");
    vector<string> svec1000;
    svec1000.reserve(1024);
    while (file1000 >> word)
    {
        svec1000.push_back(word);
    }
    svec1000.resize(svec1000.size() + svec1000.size() / 2);
    cout << svec1000.capacity() << endl;

    ifstream file1048("data1048.txt");
    vector<string> svec1048;
    svec1048.reserve(1024);
    while (file1048 >> word)
    {
        svec1048.push_back(word);
    }
    svec1048.resize(svec1048.size() + svec1048.size() / 2);
    cout << svec1048.capacity() << endl;
}