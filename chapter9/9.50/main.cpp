// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> vec = {"0", "1", "1", "2", "3", "5", "8", "13", "21", "55", "89"};

    int sum1 = 0;
    for (auto s : vec)
    {
        sum1 += stoi(s);
    }
    cout << sum1 << endl;

    double sum2 = 0;
    for (auto s : vec)
    {
        sum2 += stod(s);
    }
    cout << sum2 << endl;
}