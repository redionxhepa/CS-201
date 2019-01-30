#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


class Book
{
    public:
        Book ();
        Book(const Book &); //copy constructor
        Book(string title,string house,int year);
        void operator=(Book &toCopy);
        virtual ~Book();
        void setbookTitle(string);
        string getbookTitle();
        void setpublishYear(int);
        int getpublishYear();
        void setpublishHouse(string );
        void setnumOfCoAuthors(int);
        int getnumOfCoAuthors();
        string getpublishHouse();
        string * getcoAuthors();
        void setcoAuthors(string arr[]);
        void displaycoAuthors();



    private:
        string bookTitle;
        int publishYear;
        int numOfCoAuthors;
        string publishHouse;
        string *coAuthors;

};
#endif // BOOK_H
