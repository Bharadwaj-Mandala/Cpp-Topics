// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
string reverse(string s)
{

    string subStr = "";

    for (int i = s.length() - 1; i >= 0; i--)
    {
        subStr = subStr + s[i];
    }
    return subStr;
}
*/

int main()
{
    // Write C++ code here
    //"he is a developer"

    string s = "he is a developer";

    string subStr;
    subStr.clear();

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            subStr = subStr + s[i];
        }
        else
        {
            reverse(subStr.begin(), subStr.end());
            cout << subStr + s[i];
            subStr.clear();
        }
    }

    reverse(subStr.begin(), subStr.end());
    cout << subStr;

    return 0;
}
