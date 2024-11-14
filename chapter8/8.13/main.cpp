// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;
using std::ifstream;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    ifstream file("data.txt");
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(file, line))
    {
        PersonInfo info;
        record.str(line); // 注意这里并不是把 record 绑定到 line 字符串就可以了
        record.clear(); // 还要将上一轮中变成 fail 的流状态复位
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);

        // 检查 info 中存储的对象对不对
        cout << info.name << ' ';
        for (auto s : info.phones)
        {
            cout << s << ' ';
        }
        cout << endl;
    }
}