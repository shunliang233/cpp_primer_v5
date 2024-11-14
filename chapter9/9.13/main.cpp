#include <list>
#include <vector>
using std::list;
using std::vector;

int main()
{
    list<int> c1{1, 2, 3, 4, 5};
    vector<double> c2(c1.cbegin(), c1.cend());

    vector<int> c3{6, 7, 8, 9, 10};
    vector<double> c4(c3.cbegin(), c3.cend());
}