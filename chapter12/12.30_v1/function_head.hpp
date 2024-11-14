#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "QueryResult.hpp"
using std::ostream;
using std::string;
using std::ifstream;

ostream &print(ostream &os, const QueryResult &qr);
string make_plural(size_t ctr, const string &word, const string &ending);
void runQueries(ifstream &infile);