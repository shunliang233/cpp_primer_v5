// Windows Powershell: g++ -std=c++11 -Wall 6.42.cpp -o 6.42.exe ; ./6.42.exe
// Mac Zsh: g++ -std=c++11 -Wall 6.42.cpp -o 6.42.out ; ./6.42.out

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    string success = "success";
    string failure = "failure";

    cout << "Singular \"success\": " << make_plural(1, success, "es") << endl;
    cout << "Plural  \"success\": " << make_plural(2, success, "es") << endl;
    cout << "Singular \"failure\": " << make_plural(1, failure) << endl;
    cout << "Plural  \"failure\": " << make_plural(2, failure) << endl;
}
