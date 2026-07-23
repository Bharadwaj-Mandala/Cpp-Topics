#include <iostream>
using namespace std;
#include <string.h>

class Strings
{
private:
    char *sPtr;

public:
    Strings()
    {
        sPtr = NULL;
    }

    Strings(const char *str)
    {

        sPtr = new char[strlen(str)];
        strcpy(sPtr, str);
    }

    Strings(Strings &s1)
    {
        cout << "Copy constructor" << endl;

        sPtr = new char[strlen(s1.sPtr)];

        strcpy(sPtr, s1.sPtr);
    }

    ~Strings()
    {
        delete[] sPtr;
    }

    /*  Why we must use reference at formal parameter in the below function

        we haven't defined a proper copy constructor, passing by value creates a shallow copy.
        The original and the copy will point to the same memory.
        When the function ends, the copy’s destructor runs and deletes that memory.
        The original object is left with a "dangling pointer" to deleted memory, causing a crash.
    */
    Strings operator+(Strings &s)
    {
        cout << "+ operator" << endl;

        char *temp = new char[strlen(sPtr) + strlen(s.sPtr)];
        strcpy(temp, sPtr);
        strcat(temp, s.sPtr);
        Strings result(temp);
        delete[] temp;
        return result;
    }

    void operator=(Strings s)
    {
        cout << "Operator=" << endl;
        if (this->sPtr == NULL)
        {
            this->sPtr = new char[strlen(s.sPtr)];
        }

        strcpy(this->sPtr, s.sPtr);
    }

    void showString()
    {
        cout << this->sPtr << endl;
    }
};

int main()
{
    Strings s1("Data is ");
    Strings s2("useful");

    Strings s3 = s1;

    Strings s4;
    s4 = s1 + s2;

    s3 = s4;

    s3.showString();
    s4.showString();
}

/*

class Strings
{
private:
    char str[100];

public:
    Strings()
    {
    }

    Strings(const char *str)
    {
        strcpy(this->str, str);
    }

    void showString()
    {
        cout << str << endl;
    }

    void changeData(const char *str)
    {
        strcpy(this->str, str);
    }

    Strings operator+(Strings s)
    {
        Strings temp;
        strcpy(temp.str, strcat(this->str, s.str));
        return temp;
    }

    ~Strings()
    {
        // cout << "Destructor" << endl;
    }
};

int main()
{

    Strings s1("Data");
    Strings s2("this a changed string");

    Strings s3 = s1 + s2;
    s3.showString();
}
    */