#pragma once
#include <string>
using std::string;

struct Person
{
    string MingZi;
    string DiZhi;
    string name() const { return MingZi; }
    string address() const { return DiZhi; }
};