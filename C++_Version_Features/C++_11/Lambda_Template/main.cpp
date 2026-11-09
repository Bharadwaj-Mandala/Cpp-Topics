#include <iostream>
using namespace std;

template <typename T> /*  This template lambda is C++11 feature   */
T sum(T a, T b)       /*  This syntax "[](auto a, auto b) { return a + b; }" is C++14 feature   */
{
    auto lambda = [](T a, T b) -> T
    {
        return a + b;
    };
    return lambda(a, b);
}

int main()
{
    cout << sum(11, 12) << endl;
    cout << sum(11.1, 12.1) << endl;
}