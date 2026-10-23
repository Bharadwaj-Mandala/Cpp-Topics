#include <iostream>
using namespace std;

class GfG
{
    int x, y, z;

public:
    GfG()
    {
        cout << "zero" << endl;
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    GfG(int x) : GfG()
    {
        cout << "One" << endl;
        this->x = x;
    }

    GfG(int x, int y) : GfG(x)
    {
        cout << "Two" << endl;
        this->y = y;
    }

    GfG(int x, int y, int z) : GfG(x, y)
    {
        cout << "Three" << endl;
        this->z = z;
    }

    void show()
    {
        cout << x << ' ' << y << ' '
             << z;
    }
};

/*
A heavy initialized constructor calls a less initialized constructor and continuous till the least that is the default constructor.
*/

int main()
{
    GfG obj(1);
    obj.show();
    return 0;
}