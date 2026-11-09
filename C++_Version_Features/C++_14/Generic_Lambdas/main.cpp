#include <iostream>
using namespace std;

int main()
{
    auto sum = [](auto a, auto b)
    {
        return a + b;
    };

    cout << sum(11, 12) << endl;
    cout << sum(11.1, 12.1) << endl;

    return 0;
}