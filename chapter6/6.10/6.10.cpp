// Windows Powershell: g++ -std=c++11 -Wall 6.10.cpp -o 6.10.exe ; ./6.10.exe
// Mac Zsh: g++ -std=c++11 -Wall 6.10.cpp -o 6.10.out ; ./6.10.out

#include <iostream>
using std::cout;
using std::endl;

void change(int *a, int *b)
{
    int middle = *a;
    *a = *b;
    *b = middle;
}

int main()
{
    int i = 42, j = 10;
    cout << i << " " << j << endl;
    change(&i, &j);
    cout << i << " " << j << endl;
    return 0;
}