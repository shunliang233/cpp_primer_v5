#include <vector>
using std::vector;

int main()
{
    // 6 种初始化 vector 的方法
    vector<int> v1;
    vector<int> v2(v1);
    vector<int> v3{0, 1, 2, 3, 4, 5};
    vector<int> v4(v3.begin(), v3.end());
    vector<int> v5(10);
    vector<int> v6(10, 2);
}