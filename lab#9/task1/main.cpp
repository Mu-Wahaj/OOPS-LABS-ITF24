#include"complex.h"

int main()
{
Complex c1(3, 4);
Complex c2(3, 4);
// Testing various operator overloads
Complex c3 = c1 + c2; // Complex + Complex
Complex c4 = c2 + 5.6; // Complex + double
Complex c5 = 5.6 + c2; // double + Complex (friend function)
// Cascading demonstration
Complex c6 = c1 + c2 + c3;
c3.display();
c4.display();
c5.display();
// Relational operators
if (c1 == c2) {
cout << "c1 and c2 are equal" << endl;
}
return 0;
}