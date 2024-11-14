// Windows Powershell: g++ -std=c++11 -Wall main.cpp -o main.exe ; ./main.exe
// Mac Zsh: g++ -std=c++11 -Wall main.cpp -o main.out ; ./main.out

#include <iostream>
#include <vector>
#include <boost/type_index.hpp>
using std::vector;
using std::cout;
using std::endl;

int main(){
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    auto it3 = v1.cbegin();
    auto it4 = v2.cbegin();

    cout << "Type of it1: " << boost::typeindex::type_id_with_cvr<decltype(it1)>().pretty_name() << endl;
    cout << "Type of it2: " << boost::typeindex::type_id_with_cvr<decltype(it2)>().pretty_name() << endl;
    cout << "Type of it3: " << boost::typeindex::type_id_with_cvr<decltype(it3)>().pretty_name() << endl;
    cout << "Type of it4: " << boost::typeindex::type_id_with_cvr<decltype(it4)>().pretty_name() << endl;
}

