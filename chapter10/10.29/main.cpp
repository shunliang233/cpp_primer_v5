// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::string;
using std::vector;

int main()
{
    // 用输入流迭代器读取文件，超级简单
    ifstream file("data.txt");
    istream_iterator<string> in(file), eof;
    vector<string> vec(in, eof);

    // 输出 vector
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
}