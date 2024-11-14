// 要用 C++17 标准, -std=c++17

#include <algorithm>
#include <bitset>
#include <iostream>
#include <type_traits>
#include <vector>
#define PRTBIN(x)                                                                      \
    do                                                                                 \
    {                                                                                  \
        std::vector<std::bitset<8>> v((char *)(&x), (char *)(&x) + sizeof(x));         \
        int one = 1;                                                                   \
        if (*(char *)&one == 1)                                                        \
        {                                                                              \
            std::reverse(v.begin(), v.end());                                          \
            if constexpr (std::is_array_v<decltype(x)>)                                \
            {                                                                          \
                using pab_t =                                                          \
                    std::bitset<8>(*)[sizeof(std::remove_all_extents_t<decltype(x)>)]; \
                std::reverse(pab_t(v.data()), pab_t(v.data() + v.size()));             \
            }                                                                          \
        }                                                                              \
        std::cout << #x "(base2) = ";                                                  \
        for (auto const &b : v)                                                        \
            std::cout << b << ' ';                                                     \
        std::cout << '\n';                                                             \
    } while (0)
int main()
{
    char a = 42;
    PRTBIN(a);
    int b = 0x01020304;
    PRTBIN(b);
    long long c = -2;
    PRTBIN(c);
    float f = -0.0;
    PRTBIN(f);
    double d = 3.14;
    PRTBIN(d);
    const char s[] = "abc";
    PRTBIN(s);
    short sa[4] = {1, 2, 3, 4};
    PRTBIN(sa);
}