// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::string;

// stoi 函数使用实参依赖查找，不用特地说明其来自 std 命名空间
class date
{
private:
    unsigned year = 0;
    unsigned month = 0;
    unsigned day = 0;

public:
    date() = default;
    date(const string &s)
    {
        istringstream is(s);
        string word; // 分别存储年月日

        is >> word; // 年
        year = stoi(word);

        is >> word; // 月
        if (word == "January" || word == "Jan" || word == "Jan." || word == "1")
            month = 1;
        else if (word == "February" || word == "Feb" || word == "Feb." || word == "2")
            month = 2;
        else if (word == "March" || word == "Mar" || word == "Mar." || word == "3")
            month = 3;
        else if (word == "April" || word == "Apr" || word == "Apr." || word == "4")
            month = 4;
        else if (word == "May" || word == "May." || word == "5")
            month = 5;
        else if (word == "June" || word == "Jun" || word == "Jun." || word == "6")
            month = 6;
        else if (word == "July" || word == "Jul" || word == "Jul." || word == "7")
            month = 7;
        else if (word == "August" || word == "Aug" || word == "Aug." || word == "8")
            month = 8;
        else if (word == "September" || word == "Sep" || word == "Sep." || word == "9")
            month = 9;
        else if (word == "October" || word == "Oct" || word == "Oct." || word == "10")
            month = 10;
        else if (word == "November" || word == "Nov" || word == "Nov." || word == "11")
            month = 11;
        else if (word == "December" || word == "Dec" || word == "Dec." || word == "12")
            month = 12;

        is >> word; // 日
        day = stoi(word);
    }
    void print() const { cout << year << '.' << month << '.' << day << endl; }
};

int main()
{
    date today("2024 February 28");
    date tomorrow("2024 Mar 1");
    today.print();
    tomorrow.print();
}