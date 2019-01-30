
    #include "Library.h"
    #include "Book.h"
    #include <string>
    #include<iostream>
    #include <stdio.h>
    #include <string.h>


    using namespace std;


    Library::Library()
    {
         // initiate the  library with one empty book
         numberOfBooks=0;  //we will always have an empty book
         cout<<"Congratulations ! You are the owner of an empty library ! "<<endl;
         books=NULL;
    }

    //destructor
    Library::~Library()
    {
           delete[] books;

    }

     //This method is a helping method,since I could not find directly a comparing method in the standard  library I wrote it myself
      int Library:: compareStringsCaseInsensitive( string  a, string b){
          //if two string are equal Insensitively return 1 otherwise 0
          if(a.length() != b.length()){
            return 0;
          }
          for (int i =0; i<a.length() ;i++){
           if ( toupper(a[i]) != toupper(b[i])){
                 return 0;   //The strings are not equal
            }
           }
         return 1;//If there is no indications of inequality it means the strings are the same

      }
     int Library:: getNumberOfBooks( ) {
        return numberOfBooks;
    }
     void Library::setnumberOfBooks(int number){
         numberOfBooks=number;
     }

     //Helping method for debugg,returns the adress of the first book
     Book* Library :: returnFirstBook( ){
        return books;
    }
    //Helping method to check for a book,it returns its address and the index of the book found is passed by reference
     Book * Library:: findBook(string title,int &index ) {
           index =0;
          for (int i=0 ; i<numberOfBooks; i++){
            if(compareStringsCaseInsensitive(title,books[i].getbookTitle()) ==1) {
               index =i;
               return &books[i];
            }
           }
           return NULL ;  //A null pointer should be sent otherwise
    }
 // Adds a book in the library
    void Library:: addBook( string bookTitle, string publishingHouse, int publishingYear ){
        //firstly we have to check whether it exist previously
       if(getNumberOfBooks()==0) {
            //First book to be attached
             books = new Book[1];
            // Book * tobeAdded  = new Book(bookTitle,publishingHouse,publishingYear);
            Book tobeAdded(bookTitle, publishingHouse, publishingYear);

           //  books[0]=* tobeAdded;
               books[0]=tobeAdded;
             setnumberOfBooks(getNumberOfBooks()+1);
        }
        else {
              int index;   //For sake of generality of the method we have to put the index as input in the find method
              if ((findBook(bookTitle,index))!=NULL) {
                  cout<<"The  book is still there! You do not have to add it again !"<<endl;
                  return;
              }
              else {
               // (Check)   Book * tobeAdded  = new Book(bookTitle,publishingHouse,publishingYear); //create the new book object which will be stored in the heap
                Book tobeAdded(bookTitle, publishingHouse, publishingYear);
                   int newSize = getNumberOfBooks() + 1;
                    //the array will change its size with 1
                               // the number of books has to be updated
                   Book * books2 = new Book[newSize];
                   for ( int i = 0 ; i<newSize-1 ; i++) {   //newSize-1 was the old size,firstly we will copy and then add the new one
                      books2[i]=books[i];
                    }
                  //  books2 [newSize-1]= *tobeAdded; //now all the old books were copied and then we add the new book
                    books2 [newSize-1]= tobeAdded;
                    if(getNumberOfBooks() != 0){
                        delete []books;  //delete the old trace of the previous matrix
                    }
                    books=books2;    //point to the data of the new matrix
                    setnumberOfBooks(newSize);
              }
       }
    }
     void Library:: removeBook( string bookTitle ) {

          int indx; // index of the object in the array if it is going to be found,initially zero
         if(getNumberOfBooks()==0) {
             cout<<"Error ! You have an empty Library! "<<endl;
             return;
         }
         if ((findBook(bookTitle,indx))!=NULL) {
                Book * books2 = new Book[getNumberOfBooks()-1];
                for (int i=0 ; i<indx ; i++){
                    //The mapping of the indexes will be one to one until the index of the deleted object
                        books2[i]=books[i];
                }
                for(int i = indx+1; i<getNumberOfBooks();i++){
                    //We shift the indexes by 1
                        books2[i-1]=books[i];
                }
                if(getNumberOfBooks()!=0){
                     delete []books;
                }

                 books=books2;
                 setnumberOfBooks(getNumberOfBooks()-1);
                 return ;
         }
         else {
            cout<<"Error ! You cannot discard a book that is not there!  "<<endl;
            return;
         }
     }

     void Library :: addCoauthor( string titleBook, string nameCoauthor ){
         //At first search for the book
         int index; //variable to store  the index of the found object(if found)
         bool found = false;  //a boolean variable to check if the coAuthor is in the list
         if(findBook(titleBook,index)== NULL){
             cout<<"Your book is not found,as result we cannot add coauthor"<<endl;
         }
         else {
         //The book was there,now search for the coAuthor to be added,if it is there prompt error.Otherwise add it
             for (int i=0; i<books[index].getnumOfCoAuthors();i++){
                if( compareStringsCaseInsensitive((books[index].getcoAuthors()[i]),nameCoauthor)==1  ){
                    cout<<"This coauthor is in the list.You do not have to add it again "<<endl;
                    found=true;
                    break;
                }
             }
             //if not found add it to the list
             if ( found==false){
                //If the coauthors is empty
                string isempty="Empty";
                if(compareStringsCaseInsensitive((books[index].getcoAuthors()[0]),isempty)==1){
                    (books[index].getcoAuthors()[0])=nameCoauthor;

                }else {
                int newsize = books[index].getnumOfCoAuthors()+1;
                 books[index].setnumOfCoAuthors(newsize);
                 string * temp = new string[newsize];  // the new temp array has size + 1
                for (int i =0 ;i<newsize-1;i++){
                    temp[i]=books[index].getcoAuthors()[i];      //copy each index one by one
                }
                temp[newsize-1] =nameCoauthor;  //add to the last index the new coAuthor's name
                //Now the new temp array is completed.Next step is to delete the old array
                delete [] books[index].getcoAuthors() ;
                //Point the new array to the pointer of the old array
                 books[index].setcoAuthors(temp) ;
                }
             }
         }

     }
     //Remove Coauthor method
     void Library :: removeCoauthor( string titleBook, string nameCoauthor ){
         //At first search for the book
         int index; //variable to store  the index of the found object(if found)
         int foundIndex;  //index of the coAuthor in the list of the coAuthors
         bool found = false;
         if(findBook(titleBook,index)== NULL){
             cout<<"Your book is not found,as result we cannot delete coauthor"<<endl;
         }
         else {

                //The book was there,now search for the coAuthor to be deleted,if it is not there prompt error.Otherwise delete it
                for (int i=0; i<books[index].getnumOfCoAuthors();i++){
                 //If the coAuthor is found delete it and perform array operations
                    if( compareStringsCaseInsensitive((books[index].getcoAuthors()[i]),nameCoauthor)==1  ){
                       foundIndex=i;
                       found =true;
                    }
                 }

                if (found == true){ //bracket missing
                    int newsize = books[index].getnumOfCoAuthors()-1;
                    if (newsize==0){
                       books[index].getcoAuthors()[0]="Empty";
                       return;
                    }
                    else {
                       books[index].setnumOfCoAuthors(newsize);
                       string * temp = new string[newsize];  // the new temp array has size - 1
                       for (int i =0 ;i<foundIndex;i++){
                           temp[i]=books[index].getcoAuthors()[i]; //copy each index one by one until index
                       }
                       for ( int i = foundIndex+1 ;i<newsize+1;i++){
                        temp[i-1]=books[index].getcoAuthors()[i];    //the mapping will not be one to one tight now
                        }
                       //Now the new temp array is completed.Next step is to delete the old array
                       delete [] books[index].getcoAuthors() ;
                       //Point the new array to the pointer of the old array
                       books[index].setcoAuthors(temp) ;
                    }
               }
               if (found==false ) {
                    cout<<"This coauthor is not in  the list or the list is empty.You cannot delete it"<<endl;
                    return ;
                 }
             }
      }
      //Method which displays all books
      void  Library :: displayAllBooks() {
          int counter =0;
          if(numberOfBooks==0){
            cout<<"--Empty--"<<endl;
          }
          for (int  i=0; i<getNumberOfBooks() ; i++){
            counter=i;
            counter++;
            cout<< "Book \" " << books[i].getbookTitle()<< " \", publishing year " <<books[i].getpublishYear()<< endl;
          }
      }
     //Method which displays a book with its details
      void Library :: displayBook( string bookTitle ){
          int indx;
          if ((findBook(bookTitle,indx))!=NULL){
              cout<<books[indx].getbookTitle()<<", "<<books[indx].getpublishHouse()<<", "<<books[indx].getpublishYear()<<endl;
              books[indx].displaycoAuthors();

          }else {
              cout<<"--Empty--"<<endl;
          }
      }
      //Displays all the books of a particular author
       void Library :: displayAuthor( string authorName ){
           cout<<"Author " <<authorName<<endl;
           bool atLeastone=false;
           for(int i=0; i<getNumberOfBooks();i++){
            for(int j=0; j<books[i].getnumOfCoAuthors();j++){
                if(books[i].getcoAuthors()[j]==authorName){
                    atLeastone=true;
                 cout<< "Book \" " << books[i].getbookTitle()<< " \", publishing year " <<books[i].getpublishYear()<< endl;
                }
            }
           }
           if(atLeastone==false){
            cout<<"--Empty--"<<endl;
           }
       }



