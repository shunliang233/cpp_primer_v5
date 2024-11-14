#include <iostream>
#include <algorithm>
#include "Foo_v1.hpp"
using std::cout;
using std::endl;

Foo_v1 Foo_v1::sorted() &&
{
    cout << "运行右值版本" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo_v1 Foo_v1::sorted() const &
{
    static int count = 0;
    cout << "运行左值版本" << endl;
    Foo_v1 ret(*this);

    if (++count >= 100)
        return ret;
    else
        return ret.sorted();
}