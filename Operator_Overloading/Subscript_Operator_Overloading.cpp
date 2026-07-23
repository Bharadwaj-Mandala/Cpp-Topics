#include <iostream>
using namespace std;

class Base
{
private:
    struct Data
    {
    public:
        int key;
        string value;
    };

    Data d[10];

public:
    virtual void print()
    {
        cout << "Base" << endl;
    }

    Base()
    {
        d[0].key = 0;
        d[0].value = "Data_0";

        d[1].key = 1;
        d[1].value = "Data_1";

        d[2].key = 2;
        d[2].value = "Data_2";

        d[3].key = 3;
        d[3].value = "Data_3";
    }

    string operator[](int key)
    {
        return d[key].value;
    }
};

int main()
{

    Base b1;

    cout << b1[3];
}
