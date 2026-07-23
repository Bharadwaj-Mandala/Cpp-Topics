#include <iostream>
using namespace std;

class Dummy
{
public:
    int a, b;
    int *p;

public:
    void setData(int x, int y, int z)
    {
        a = x;
        b = y;
        *p = z;
    }
    void showData()
    {
        cout << "a = " << a << " b = " << b << " c = " << *p;
    }

    Dummy()
    {
        p = new int;
    }
    /*
        Dummy(Dummy &d)
        {

            this->a = d.a;
            this->b = d.b;

            this->p = new int;
            *this->p = *(d.p);
        }
    */
    void operator=(Dummy d)
    {
        this->a = d.a;
        this->b = d.b;
        *this->p = *(d.p);
    }

    ~Dummy()
    {
        cout << endl
             << "Destructor called" << endl;
        delete p;
    }
};

int main()
{
    Dummy d1;

    d1.setData(3, 4, 5);
    Dummy d2; //= d1;
    d2 = d1;

    d2.showData();
    cout << endl;
    d1.showData();
}

/*
    While making a deep copy, i.e. while allocating memory
    dynamically there are two approaches, they are following

        1.  Copy constructor
        2.  Copy assignment operator

    1.  Copy constructor - While using copy constructor, we must
        manually create memory and assign the values.

    2.  Copy assignment operator - While using Copy assignment
        operator there are two conditions, they are following

        i.  Pass by value to Copy assignment operator function

                Here the existance of Copy constructor is mandatory
                Because pass by value here means

                void operator=(Dummy d)

                Here Dummy d is instanciated with it's own object as
                actual parameter, this rises to call of Copy constructor.
                if Copy constructor is not availale, Dummy d created in
                the form of formal parameter will call destructor before
                the end of
                void operator=(Dummy d){
                ---
                ---
                }

                and it will free memory of d1 which was passed as actual parameter
                and causes dangling pointer and double free issues.



        ii. Pass by reference to Copy assignment operator function

                Here the existance of Copy constructor is
                not mandatory, the actual parameter is passed by reference
                thus no object is created during call to copy assignment
                operator function at formal parameter

                void operator=(Dummy &d)

                Here d is the reference of d1 in below statement
                d2 = d1;

*/