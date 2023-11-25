// Program: Publication and Sales Class
// Programmer: Muhammad Maaz Ahmad
// Date: 23-11-2023
// Compiler: Microsoft Visual Studio 2022 Community Edition
#include <iostream>
#include <string>
#define MONTHS 3 //define value of Macro of MONTHS 3
using namespace std;

// Start: Classes
class Publication { // declare a class publication
    string title; // title of the publication
    float price; // price of the publication
public:
    Publication(string ttitle = "", int pprice = 0) :price(pprice) {}
    void getdata();
    void putdata() const; // using const to prevent any change in data members in this member functions
};

class Sales { // declare a class sales
    float sales[MONTHS]; // sale value of previous 3 months of the publication
public:
    Sales(float ssale) :sales{ssale} {}
    void getdata();
    void putdata() const;
};

// declare a class book which inherits publication and sales class
class Book : virtual public Publication, virtual public Sales { // use virtual to solve repeated base class problem
    int page_count; // total page count of the book (publication)
public:
    Book(string ttitle = "", int pprice = 0, float ssales = 0, int ppage_count = 0) :Publication(ttitle, pprice), Sales(ssales), page_count(ppage_count) {}
    void getdata();
    void putdata() const; // using const to prevent any change in data members in this member functions
};

// declare a class tape which inherits publication and sales class
class Tape : virtual public Publication, virtual public Sales { // use virtual to solve repeated base class problem
    float minutes; // total minutes of the tape (publication)
public:
    Tape(string ttitle = "", int pprice = 0, float ssales = 0, int mminutes = 0) :Publication(ttitle, pprice), Sales(ssales), minutes(mminutes) {}
    void getdata();
    void putdata() const; // using const to prevent any change in data members in this member function
};

// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //

// Start: Classes Member Function definitions

// publication class member functions

// definition of getdata() member function of publication class
void Publication::getdata() {
    cout << "Enter the title of the publication: ";
    getline(cin, title); // get title of the publication from the user
    cout << "Enter price of the publication: ";
    cin >> price; // get price of the publication from the user
}

// definition of putdata() member function of publication class
void Publication::putdata() const {
    // display title and price of the publication
    cout << "Title of the publication is: " << title << endl << "Price of the publication is: " << price << endl;
}

// End: publication class member functions

// sales class member functions
// definition of getdata() member function of sales class
void Sales::getdata() {
    cout << "Sales of Publication in previous 3 months: " << endl;
    // get sale value of previous 3 months
    for (int i = 0; i < MONTHS; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> sales[i];
    }
}

// definition of putdata() member function of sales class
void Sales::putdata() const {
    cout << "Sales of Publication in previous 3 months: " << endl;
    // display sale value of previous 3 months
    for (int i = 0; i < MONTHS; i++) {
        cout << "Month " << i + 1 << ": " << sales[i] << endl;
    }
}

// End: sales class member functions

// book class member functions

// definition of getdata() member function of book class
void Book::getdata() {
    Publication::getdata(); // call publication class getdata() member function
    Sales::getdata(); // call sales class getdata() member function
    cout << "Enter the page count of the book: ";
    cin >> page_count; // get value of page_count
}

// definition of putdata() member function of book class
void Book::putdata() const {
    Publication::putdata(); // call publication class putdata() member function
    Sales::putdata();// call sales class putdata() member function
    cout << endl << "Page count of the book is: " << page_count << endl; // display value of page_count
}

// End: book class member functions

// tape class member functions

// definition of getdata() member function of tape class
void Tape::getdata() {
    Publication::getdata(); // call publication class getdata() member function
    Sales::getdata(); // call sales class getdata() member function
    cout << "Enter the duration of the audio tape in minutes: ";
    cin >> minutes; // get value of minutes
}

// definition of putdata() member function of tape class
void Tape::putdata() const {
    Publication::putdata(); // call publication class putdata() member function
    Sales::putdata();// call sales class putdata() member function
    cout << endl << "The duration of the audio tape in minutes is: " << minutes << endl; // display value of minutes
}

// End: tape class member functions

// End: Classes Member Functions

// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //

// tester
int main()
{
    // Create objects for Book and Tape
    Book b1;
    Tape t1;

    // Display Book Information
    cout << "Book information: " << endl;

    // Get and Display data for Book
    b1.getdata();
    b1.putdata();

    // Display Audio Tape Information
    cout << endl << "Audio Tape information: " << endl;
    cin.ignore();

    // Get and Display data for Audio Tape
    t1.getdata();
    t1.putdata();
    system("pause");
    return 0;
}