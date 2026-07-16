#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyVector
{
private:
    T *arr;          //  Pointer to dynamically allocated array
    size_t size;     //  Number of elements in the vector
    size_t capacity; //  Capacity of the vector

public:
    MyVector() : size(0), capacity(1) //  constructor
    {
        arr = new T[capacity];
    }

    ~MyVector() //  Destructor
    {
        delete[] arr;
    }

    MyVector(MyVector &other) //: size(other.size), capacity(other.capacity) //  Copy constructor
    {

        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];

        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    MyVector &operator=(MyVector &other) //  Copy assignment operator
    {
        if (this == &other) //  Self assignment check
        {
            return *this;
        }

        delete[] arr; //  Free existing memory
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];

        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    MyVector(MyVector &&other) //  Move constructor
    {
        arr = other.arr;
        size = other.size;
        capacity = other.capacity;

        other.arr = nullptr; //  Nullify the other vector's pointer
        other.size = 0;
        other.capacity = 0;
    }

    MyVector &operator=(MyVector &&other) //  Move assignment operator
    {
        if (this == &other) //  Self assignment check
        {
            return *this;
        }

        delete[] arr; //  Release the current memory

        arr = other.arr; //  Take ownership of other vector's data
        size = other.size;
        capacity = other.capacity;

        other.arr = nullptr; //  Reset the other vector
        other.size = 0;
        other.capacity = 0;

        return *this;
    }

    void resize()
    {
        capacity = capacity * 2;
        T *new_arr = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
    }

    void push_back(T element) //  Add element
    {
        if (size == capacity)
        {
            resize(); //    Resize If we reach capacity
        }
        arr[size] = element;
        ++size;
    }

    void pop_back() //  Remove last element
    {
        if (size > 0)
        {
            --size;
        }
    }

    size_t get_size() const
    {
        return size;
    }

    size_t get_capacity() const
    {
        return capacity;
    }

    T &operator[](size_t index)
    {
        if (index >= size)
        {
            throw out_of_range("Index out of bounds");
        }

        return arr[index];
    }
};

int main()
{
    MyVector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);

    // Test copy constructor
    MyVector<int> vec2 = vec1;

    // Test move constructor
    MyVector<int> vec3 = std::move(vec1);

    // Test copy assignment
    vec2 = vec3;

    // Test move assignment
    vec3 = std::move(vec2);

    std::cout << "Vector elements in vec3: ";
    for (size_t i = 0; i < vec3.get_size(); ++i)
    {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}