#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//  function call using function pointer
/*
void print(int n)
{
    cout << n << endl;
}
*/

//  function call using functor+33
/*
class Print
{
public:
    void print(int n)
    {
        cout << n << endl;
    }

    void operator()(int n)
    {
        print(n);
    }
};
*/

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5, 16, 17, 18, 19, 20};

    /*for_each(v1.begin(), v1.end(), print);*/   //  function call using function pointer
    /*for_each(v1.begin(), v1.end(), Print());*/ //  function call using functor
    for_each(v1.begin(), v1.end(), [](int n)     //  function call using lambda function
             { cout << n << endl; });

    return 0;
}