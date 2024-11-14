// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <functional>
#include <string>
#include <vector>
using namespace std::placeholders;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int main()
{
    string s = "Hello";
    vector<int> vec = {1, 3, 4, 5, 7, 3, 76};
    cout << *find_if(vec.cbegin(), vec.cend(), bind(check_size, s, _1)) << endl;
}