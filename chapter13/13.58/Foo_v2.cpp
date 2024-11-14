#include <iostream>
#include <algorithm>
#include "Foo_v2.hpp"
using std::cout;
using std::endl;

Foo_v2 Foo_v2::sorted() &&
{
    cout << "运行右值版本" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo_v2 Foo_v2::sorted() const &
{
    cout << "运行左值版本" << endl;
    return Foo_v2(*this).sorted();
}