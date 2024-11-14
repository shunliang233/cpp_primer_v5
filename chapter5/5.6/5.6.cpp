// Windows Powershell: g++ -std=c++11 -Wall -o 5.6.exe 5.6.cpp ; ./5.6.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.6.out 5.6.cpp ; ./5.6.out

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int grade = 89;
    string letter_grade;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

    // 这样写虽然字很少，但是非常难理解（圆括号还能全都去掉）
    grade < 60 ? (letter_grade = "F") : (letter_grade = scores[(grade - 50) / 10]);
    grade != 100 && grade >= 60 ? (grade % 10 > 7 ? (letter_grade += "+") : (grade % 10 < 3 ? (letter_grade += "-") : letter_grade)) : letter_grade;

    cout << letter_grade << endl;
    return 0;
}