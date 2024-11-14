// Windows Powershell: g++ -std=c++11 -Wall 6.33.cpp -o 6.33.exe ; ./6.33.exe
// Mac Zsh: g++ -std=c++11 -Wall 6.33.cpp -o 6.33.out ; ./6.33.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 使用该函数可以打印 vec 中的所有元素。
// 输出工作在函数中完成，因此函数不需要返回值。
// 当 vec 非空时，输出 vec 中的第一个元素，再将 vec 的第一个元素删掉，递归运行函数，直到 vec 为空。
// 注意必须传值参数，不然实参 vec 就会被删干净。
void vector_int(vector<int> vec)
{
    if (!vec.empty())
    {
        cout << vec[0] << endl;
        vec.erase(vec.begin());
        vector_int(vec);
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    vector_int(vec);
}