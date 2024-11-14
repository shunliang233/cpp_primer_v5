#include <vector>
#include <iostream>
using std::cerr;
using std::endl;
using std::vector;

// const_iterator 是底层 const, 表示迭代器指向的值是 const, 而不是迭代器本身的值不能变
vector<int>::const_iterator find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
    while (begin != end)
    {
        if (*begin == i)
        {
            break;
        }
        ++begin;
    }

    if (begin != end)
    {
        return begin;
    }
    else
    {
        cerr << "Didn't find the number." << endl;
        return begin;
    }
}