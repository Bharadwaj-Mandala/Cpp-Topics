#include <memory>
#include <iostream>
using namespace std;

class B;

class A
{
public:
    weak_ptr<B> p1; /*  shared_ptr<B> p1; */

    void set_ptr(shared_ptr<B> &ptr1)
    {
        p1 = ptr1;
    }
    ~A()
    {
        cout << "A Destructor" << endl;
    }
};

class B
{
public:
    weak_ptr<A> p2; /*  shared_ptr<A> p2    */

    void set_ptr(shared_ptr<A> &ptr2)
    {
        p2 = ptr2;
    }
    ~B()
    {
        cout << "B Destructor" << endl;
    }
};

void f1()
{
    shared_ptr<A> objAptr(new A());
    shared_ptr<B> objBptr(new B());
    objAptr->set_ptr(objBptr);
    objBptr->set_ptr(objAptr);
    cout << objAptr.use_count() << endl;
    cout << objBptr.use_count() << endl;
}

int main()
{
    f1();
    cout << endl;
    return 0;
}