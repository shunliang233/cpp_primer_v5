// Windows Powershell: g++ -std=c++11 -Wall -o condition.exe condition.cpp ; gc data.txt | ./condition.exe
// Mac Zsh: g++ -std=c++11 -Wall -o condition.out condition.cpp ; ./condition.out < data.txt

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    // 读入所有成绩
    int tmp_grade = 0;
    vector<int> grade;
    while (cin >> tmp_grade)
        grade.push_back(tmp_grade);

    // 转化为成绩等级
    vector<string> final_grade;
    for (auto i : grade)
        i > 100 || i < 0 ? final_grade.push_back("N/A") : i <= 100 && i >= 90 ? final_grade.push_back("high")
                                                      : i < 90 && i >= 75     ? final_grade.push_back("pass")
                                                      : i < 75 && i >= 60     ? final_grade.push_back("low")
                                                                              : final_grade.push_back("fail");

    // 输出成绩等级
    for (auto i : final_grade)
        cout << i << ' ';
    cout << endl;

    return 0;
}