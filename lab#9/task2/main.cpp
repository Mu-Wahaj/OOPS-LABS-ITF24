#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    MyVector v1;             
       MyVector v2(10);        

    cout << "v1 size: " << v1.get_size() << ", capacity: " << v1.get_capacity() << endl;
    cout << "v2 size: " << v2.get_size() << ", capacity: " << v2.get_capacity() << endl;

    for (int i = 1; i <= 7; i++)
        v1.push_back(i);

    v1.print();

    v1.pop_back();
    v1.print();

    v1.insert(2, 99);
    v1.print();

    v1.remove(99);
    v1.print();

    int idx = v1.search(5);
    cout << "Index of 5: " << idx << endl;

    v1.reverse();
    v1.print();

    v1.clear();
    cout << "v1 size after clear: " << v1.get_size() << endl;

    MyVector a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    MyVector b = a; 
    b.print();

    MyVector c;
    c = a;           
    c.print();

    MyVector x, y;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);

    y.push_back(4);
    y.push_back(5);

    MyVector z = x + y;
    z.print();

    x += y;
    x.print();

    cout << boolalpha;
    cout << "(a == b): " << (a == b) << endl;
    cout << "(a != c): " << (a != c) << endl;

    MyVector t;
    cout << "t.isEmpty(): " << t.isEmpty() << endl;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    cout << "t.isMonotonicallyIncreasing(): " << t.isMonotonicallyIncreasing() << endl;

    return 0;
}
