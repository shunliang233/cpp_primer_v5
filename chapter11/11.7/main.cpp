// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <map>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<string>> imap = {{"MengDe", {"WenDi", "YouLa", "AnBo"}}, {"LiYue", {"KeQing", "GanYu", "NingGuang"}}};
    imap["MengDe"].push_back("BaBaLa"); // 向已有国家添加人物
    imap["DaoQi"] = {"TuoMa", "LinHua", "ZaoYou"}; // 添加新国家
}
