// Windows Powershell: g++ -std=c++11 -Wall -o main.exe main.cpp ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall -o main.out main.cpp ; ./main.out

#include <iostream>
#include <map>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::vector;

int main()
{
    multimap<string, string> imap = {{"MengDe", "YouLa"}, {"MengDe", "WenDi"}, {"LiYue", "KeQing"}, {"LiYue", "KeQing"}};
    imap.insert({"MengDe", "BaBaLa"});                                           // 向已有国家添加人物
    imap.insert({{"DaoQi", "TuoMa"}, {"DaoQi", "LinHua"}, {"DaoQi", "ZaoYou"}}); // 添加新国家

    auto it1 = imap.find("MengDe");
    if (it1 != imap.cend())
        imap.erase(it1);

    auto it2 = imap.find("XuMi");
    if (it2 != imap.cend())
        imap.erase(it2);

    cout << imap.size() << endl;
}