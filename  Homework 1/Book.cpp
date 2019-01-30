
    #include "Book.h"
    #include<iostream>
    #include <stdio.h>
    #include <string.h>
    using namespace std;


    Book::Book()
    {
             bookTitle = "empty";
             publishHouse = "empty";
             publishYear =0;
             numOfCoAuthors =1;   //the size will be by default 1 so to show empty
             coAuthors= new string[1];
             coAuthors[0]="Empty";   // at first the book added will not have a coauthors list initialized
    }

    Book::Book(string title,string house,int year)
    {
             bookTitle = title;
             publishHouse = house;
             publishYear =year;
             numOfCoAuthors=1;
             coAuthors= new string[1];
             coAuthors[0]="Empty";
    }

    //Copy constructor
    Book:: Book (const Book & toCopy) {
         bookTitle= toCopy.bookTitle;
         publishYear=toCopy.publishYear;
         publishHouse=toCopy.publishHouse;
         numOfCoAuthors=toCopy.numOfCoAuthors;
        if(numOfCoAuthors >0) {
            coAuthors = new string[numOfCoAuthors];
            for (int i = 0 ; i<numOfCoAuthors;i++){
               coAuthors[i]=toCopy.coAuthors[i];
            }
        }
        else {
            coAuthors=NULL;
        }
    }
    //Destructor
    Book::~Book()
    {
     if(numOfCoAuthors != 0){
       delete[] coAuthors;
      }
    }
    //Overloading of equal operator
     void Book::operator=(Book &toCopy)
    {
            if ( numOfCoAuthors != toCopy.numOfCoAuthors ) {
                if (numOfCoAuthors > 0){
                    delete [] coAuthors;
                }
                numOfCoAuthors = toCopy.numOfCoAuthors;
                bookTitle= toCopy.bookTitle;
                publishYear=toCopy.publishYear;
                publishHouse=toCopy.publishHouse;
                if (numOfCoAuthors > 0){
                    coAuthors = new string [ numOfCoAuthors ];
                }
                else{
                    coAuthors = NULL;
                 }
            }
            for ( int i = 0; i < numOfCoAuthors; i++ ){
                 coAuthors[ i ] = toCopy.coAuthors[ i ];
            }
               //FOr the case when they are of equal size
                bookTitle= toCopy.bookTitle;
                publishYear=toCopy.publishYear;
                publishHouse=toCopy.publishHouse;


    }
    void Book :: setnumOfCoAuthors(int number ){
        numOfCoAuthors = number;
    }
    int Book ::getnumOfCoAuthors(){
        return numOfCoAuthors;
    }
    void Book:: setbookTitle(string title){
           bookTitle = title;
    }

    string Book::getbookTitle(){
         return bookTitle;
    }
    void Book:: setpublishYear(int year){
        publishYear = year;
    }
    int Book:: getpublishYear(){
        return publishYear;
    }
    void Book:: setpublishHouse(string house ){
        publishHouse = house;
    }
    string Book::getpublishHouse(){
         return  publishHouse;
    }
    void Book:: setcoAuthors(string arr []){
           coAuthors=arr;
    }
    string * Book:: getcoAuthors(){
           return coAuthors;
    }

    //Display Authors of a book
    void Book ::displaycoAuthors(){
        int i =0;
        if(coAuthors[0]=="Empty"){
            cout<<"No CoAuthors yet "<<endl;
        }
        else {
               for(int i=0 ;i<getnumOfCoAuthors();i++){
            // Counter is meant to be i+1 each time e.g for 0-th index element counter is 1
               cout<<coAuthors[i] <<endl;
             }

        }
    }
