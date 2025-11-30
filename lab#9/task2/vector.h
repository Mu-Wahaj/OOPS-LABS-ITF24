class MyVector
{
private:
int size; // Current number of elements
int capacity; // Maximum capacity
int* arr; // Dynamic array
void resize(int newCapacity); // Private helper for resizing
public:
// ========== CONSTRUCTORS & DESTRUCTOR ==========
MyVector(); // Default capacity: 5
MyVector(int capacity); // Custom capacity
MyVector(const MyVector& v); // Copy constructor
~MyVector(); // Destructor
// ========== BASIC VECTOR OPERATIONS ==========
void push_back(int element);
void pop_back();
void insert(int index, int element);
void remove(int element);
void clear();
void reverse();
int search(int element) const; // Returns index or -1 if not found
// ========== ACCESSORS & UTILITIES ==========
int get_size() const;
int get_capacity() const;
void print() const;
bool isEmpty() const;
bool isMonotonicallyIncreasing() const;
// ========== OPERATOR OVERLOADING ==========
// Assignment Operator (Rule of Three)
MyVector& operator=(const MyVector& rhs);
// Arithmetic Operators (Member Functions)
MyVector operator+(const MyVector& rhs) const; // Vector addition
MyVector& operator+=(const MyVector& rhs); // Compound addition
// Relational Operators (Member Functions)
bool operator==(const MyVector& rhs) const; // Equality check
bool operator!=(const MyVector& rhs) const; // Inequality check comparison
};