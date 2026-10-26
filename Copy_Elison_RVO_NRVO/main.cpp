#include <iostream>
using namespace std;

class Data
{
private:
    int *info;

public:
    Data()
    {
        cout << "Default constructor" << endl;
        info = new int;
        *info = 0;
    }

    ~Data()
    {
        cout << "Destructor" << endl;
        delete info;
    }

    void setInfo(int data)
    {
        *info = data;
    }

    void showInfo()
    {
        cout << *info << endl;
    }
};

Data someFunc()
{
    Data d;
    d.setInfo(11);
    return d;
}

int main()
{
    Data d1 = someFunc();
    d1.showInfo();

    return 0;
}