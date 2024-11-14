// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe input.txt output.txt
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out input.txt output.txt

#include <iostream>
#include <fstream>
#include "Sales_data.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2],ofstream::app);
    Sales_data total;
    if (input) // 确保文件被正确打开，再读取文件内容
    {
        if (read(input, total))
        {
            Sales_data trans;
            while (read(input, trans))
            {
                if (total.isbn() == trans.isbn())
                    total.combine(trans);
                else
                {
                    print(output, total) << endl;
                    total = trans;
                }
            }
            print(output, total) << endl;
        }
        else
            cerr << "No Record!" << endl;
    }
    else
        cerr << "No File!" << endl;
}