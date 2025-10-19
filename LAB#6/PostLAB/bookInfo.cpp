#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int publicationYear;
    double price;

public:
    Book(string t, string a, int year, double p)
    {
        title = t;
        author = a;
        publicationYear = year;
        price = p;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getPublicationYear() { return publicationYear; }
    double getPrice() { return price; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setPublicationYear(int y) { publicationYear = y; }
    void setPrice(double p) { price = p; }

    void displayBookInfo()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << publicationYear << endl;
        cout << "Price: $" << price << endl;
    }

    bool isAntique(int currentYear)
    {
        int age = currentYear - publicationYear;
        return age >= 50;
    }
};

int main()
{
    string title, author;
    int year, currentYear;
    double price;

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Publication Year: ";
    cin >> year;

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Current Year: ";
    cin >> currentYear;

    Book myBook(title, author, year, price);

    myBook.displayBookInfo();

    if (myBook.isAntique(currentYear))
        cout << "The book is antique." << endl;
    else
        cout << "The book is not antique." << endl;

    return 0;
}
