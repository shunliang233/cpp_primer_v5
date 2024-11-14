// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main()
{
    map<string, vector<pair<string, string>>> imap = {{"MengDe", {{"WenDi", "11.11"}, {"YouLa", "12.12"}, {"AnBo", "1.1"}}}, {"LiYue", {{"KeQing", "2.4"}, {"GanYu", "3.5"}}}};
    imap["MengDe"].push_back({"BaBaLa", "2.2"});           // 向已有国家添加人物
    imap["DaoQi"] = {{"TuoMa", "2.6"}, {"ZaoYou", "4.6"}}; // 添加新国家
}
