// Windows Powershell: g++ -std=c++11 -Wall -o 5.5.exe 5.5.cpp ; ./5.5.exe
// Mac Zsh: g++ -std=c++11 -Wall -o 5.5.out 5.5.cpp ; ./5.5.out

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
{
    int grade = 89;
    string letter_grade;

    // 这样写虽然字数比较多，但是结构明确，很容易理解
    if (grade == 100)
        letter_grade = "A++";
    else if (grade < 100 && grade >= 90)
    {
        letter_grade = "A";
        if (grade % 10 > 7)
            letter_grade += "+";
        else if (grade % 10 < 3)
            letter_grade += "-";
    }
    else if (grade < 90 && grade >= 80)
    {
        letter_grade = "B";
        if (grade % 10 > 7)
            letter_grade += "+";
        else if (grade % 10 < 3)
            letter_grade += "-";
    }
    else if (grade < 80 && grade >= 70)
    {
        letter_grade = "C";
        if (grade % 10 > 7)
            letter_grade += "+";
        else if (grade % 10 < 3)
            letter_grade += "-";
    }
    else if (grade < 70 && grade >= 60)
    {
        letter_grade = "D";
        if (grade % 10 > 7)
            letter_grade += "+";
        else if (grade % 10 < 3)
            letter_grade += "-";
    }
    else if (grade < 60 && grade >= 0)
        letter_grade = "F";
    else
        letter_grade = "N/A";

    cout << letter_grade << endl;
    return 0;
}