// Without NDEBUG: g++ -std=c++11 -Wall 6.47.cpp -o 6.47.out ; ./6.47.out
// With NDEBUG: g++ -std=c++11 -Wall -D NDEBUG 6.47.cpp -o 6.47.out ; ./6.47.out

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

// 使用该函数可以打印 vec 中的所有元素。
// 输出工作在函数中完成，因此函数不需要返回值。
// 当 vec 非空时，输出 vec 中的第一个元素，再将 vec 的第一个元素删掉，递归运行函数，直到 vec 为空。
// 注意必须传值参数，不然实参 vec 就会被删干净。
void vector_int(vector<int> vec)
{
#ifndef NDEBUG
    cerr << "Size is: " << vec.size() << endl;
#endif
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