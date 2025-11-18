#pragma once
#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other);                   // Copy constructor
    Matrix& operator=(const Matrix& other);        // Copy assignment
    ~Matrix();                                     // Destructor

    int& at(int i, int j);                         // non-const version
    int at(int i, int j) const;                    // const version

    void fillSequential();                         // fill 1..n for testing
    void display() const;                          // helper to print matrix
};


//.cpp
#include "Matrix.h"

// Constructor
Matrix::Matrix(int r, int c)
    : rows(r), cols(c)
{
    if (rows <= 0 || cols <= 0) {
        data = nullptr;
        return;
    }

    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            data[i][j] = 0;
    }
}

// Copy Constructor (deep copy)
Matrix::Matrix(const Matrix& other)
    : rows(other.rows), cols(other.cols)
{
    if (rows <= 0 || cols <= 0) {
        data = nullptr;
        return;
    }

    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            data[i][j] = other.data[i][j];
    }
}

// Copy Assignment Operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) 
        return *this;      // self-assignment check

    // Delete old memory
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    rows = other.rows;
    cols = other.cols;

    if (rows <= 0 || cols <= 0) {
        data = nullptr;
        return *this;
    }

    // Allocate new memory
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            data[i][j] = other.data[i][j];
    }

    return *this;
}

// Destructor
Matrix::~Matrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }
}

// Bounds-Checked Access (non-const)
int& Matrix::at(int i, int j) {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::out_of_range("Index out of range");
    return data[i][j];
}

// Bounds-Checked Access (const)
int Matrix::at(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::out_of_range("Index out of range");
    return data[i][j];
}

// Fill sequential values 1..n
void Matrix::fillSequential() {
    int val = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = val++;
}

// Display matrix for debugging
void Matrix::display() const {
    if (!data) {
        std::cout << "(empty matrix)\n";
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}
//.main
#include "Matrix.h"

int main() {

    // 3×3 matrix A
    Matrix A(3, 3);
    A.fillSequential();

    std::cout << "Matrix A:\n";
    A.display();

    // Copy constructor
    Matrix B = A;
    std::cout << "\nMatrix B (copy of A):\n";
    B.display();

    // Change A (prove B stays unchanged)
    A.at(0,0) = 999;

    std::cout << "\nAfter modifying A(0,0) = 999:\n";
    std::cout << "Matrix A:\n";
    A.display();

    std::cout << "\nMatrix B should remain unchanged:\n";
    B.display();

    // Copy Assignment
    Matrix C;
    C = A;

    std::cout << "\nMatrix C (assigned from A):\n";
    C.display();

    return 0;
}
