
#include <string>
#include "Book.h"
#include <stdio.h>
#include <string.h>
using namespace std;

class Library {
public:
 Library ();
 ~Library ();
 void addBook( string bookTitle, string publishingHouse, int publishingYear );
 void removeBook( string bookTitle );
 void addCoauthor( string bookTitle, string coauthorName );
 void removeCoauthor ( string bookTitle, string coauthorName );
 void displayAllBooks();
 void displayBook( string bookTitle );
 void displayAuthor( string authorName );
 int getNumberOfBooks( );
 void setnumberOfBooks(int);
 Book * returnFirstBook();
 Book * findBook(string title,int & index);          //return 1 if found or 0 otherwise
 Book *  findCoAuthor(string name);      //return 1 if found or 0 otherwise
 int compareStringsCaseInsensitive(string a, string b);


private:
    Book * books;
    int numberOfBooks;

 // ...
 // you may define additional member functions and data members,
 // if necessary
};
