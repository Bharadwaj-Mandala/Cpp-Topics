#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printElements(auto &element)
{
    for (auto const &e : element)
    {
        cout << e << endl;
    }
}

int main()
{
    auto greater = [](auto a, auto b) -> bool
    {
        return a > b;
    };

    vector<int> vi = {1, 4, 2, 1, 6, 62, 636};

    vector<double> vd = {4.62, 161.3, 62.26, 13.4, 235.5};

    vector<string> vs = {"Tom", "Harry", "Ram", "Shyam"};

    sort(vi.begin(), vi.end(), greater);

    printElements(vi);

    return 0;
}