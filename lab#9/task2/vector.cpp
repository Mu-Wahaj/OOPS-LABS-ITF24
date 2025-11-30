#include "Vector.h"
#include <math.h>
#include <iostream>
using namespace std;

void MyVector::resize(int newCapacity)
{
    int *temp = new int[newCapacity];
    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    delete[] arr;
    arr = temp;
    capacity = newCapacity;
}

MyVector::MyVector() : size(0), capacity(5)
{
    arr = new int[capacity];
}

MyVector::MyVector(int capacity) : size(0), capacity(capacity)
{
    if (capacity < 1)
        capacity = 1;
    arr = new int[capacity];
}

MyVector::MyVector(const MyVector &v)
{
    size = v.size;
    capacity = v.capacity;
    arr = new int[capacity];

    for (int i = 0; i < size; i++)
        arr[i] = v.arr[i];
}

MyVector::~MyVector()
{
    delete[] arr;
}

void MyVector::push_back(int element)
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }
    arr[size++] = element;
}

void MyVector::pop_back()
{
    if (size > 0)
    {
        size--;
    }
}

void MyVector::insert(int index, int element)
{
    if (index < 0 || index > size)
        return;

    if (size == capacity)
    {
        resize(capacity * 2);
    }

    for (int i = size; i > index; i--)

        arr[i] = arr[i - 1];

    arr[index] = element;
    size++;
}

void MyVector::remove(int element)
{
    int index = search(element);
    if (index == -1)
        return;

    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];

    size--;
}

void MyVector::clear()
{
    size = 0;
}

void MyVector::reverse()
{
    for (int i = 0; i < size / 2; i++)
        std::swap(arr[i], arr[size - 1 - i]);
}

int MyVector::search(int element) const
{
    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return i;
    return -1;
}

int MyVector::get_size() const { return size; }
int MyVector::get_capacity() const { return capacity; }

void MyVector::print() const
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool MyVector::isEmpty() const
{
    return size == 0;
}

bool MyVector::isMonotonicallyIncreasing() const
{
    for (int i = 1; i < size; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

MyVector &MyVector::operator=(const MyVector &rhs)
{
    if (this == &rhs)
        return *this;

    delete[] arr;

    size = rhs.size;
    capacity = rhs.capacity;

    arr = new int[capacity];
    for (int i = 0; i < size; i++)
        arr[i] = rhs.arr[i];

    return *this;
}

MyVector MyVector::operator+(const MyVector &rhs) const
{
    MyVector result(size + rhs.size);

    for (int i = 0; i < size; i++)
        result.push_back(arr[i]);

    for (int i = 0; i < rhs.size; i++)
        result.push_back(rhs.arr[i]);

    return result;
}

MyVector &MyVector::operator+=(const MyVector &rhs)
{
    for (int i = 0; i < rhs.size; i++)
        push_back(rhs.arr[i]);

    return *this;
}

bool MyVector::operator==(const MyVector &rhs) const
{
    if (size != rhs.size)
        return false;

    for (int i = 0; i < size; i++)
        if (arr[i] != rhs.arr[i])
            return false;

    return true;
}

bool MyVector::operator!=(const MyVector &rhs) const
{
    return !(*this == rhs);
}
