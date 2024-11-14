#pragma once
#include <iostream>
#include <vector>

class Foo_v2
{
public:
    Foo_v2 sorted() &&;
    Foo_v2 sorted() const &;

private:
    std::vector<int> data;
};