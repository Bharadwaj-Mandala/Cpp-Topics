#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton() : brightness(10), width(9), height(11)
    {
    }
    static Singleton *instance;
    int brightness;
    int width;
    int height;

public:
    static Singleton *getInstance()
    {
        if (instance == NULL)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void setHeight(int _height)
    {
        height = _height;
    }
    void setWidth(int _width)
    {
        width = _width;
    }
    void setBrightness(int _brightness)
    {
        brightness = _brightness;
    }

    int getHeight()
    {
        return height;
    }

    int getWidth()
    {
        return width;
    }

    int getBrightness()
    {
        return brightness;
    }
};

Singleton *Singleton::instance;

void someFunction()
{
    Singleton *setting = Singleton::getInstance();
    cout << setting->getHeight() << endl;
    cout << setting->getBrightness() << endl;
    cout << setting->getWidth() << endl;
}

int main()
{
    Singleton *s1 = Singleton::getInstance();

    s1->setBrightness(9);
    s1->setHeight(10);
    s1->setWidth(11);

    Singleton *s2 = Singleton::getInstance();
    cout << s2->getHeight() << endl;
    cout << s2->getBrightness() << endl;
    cout << s2->getWidth() << endl;

    someFunction();

    return 0;
}