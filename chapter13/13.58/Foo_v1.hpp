#pragma once
#include <iostream>
#include <vector>

class Foo_v1
{
public:
    Foo_v1 sorted() &&;
    Foo_v1 sorted() const &;

private:
    std::vector<int> data;
};