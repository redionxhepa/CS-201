#include "CustomerList.h"
#include "Customer.h"
#include <iostream>
#include<string>
using namespace std;

/*

This is the implementation of a list containing customer objects.The idea(construction) is based upon the slides

*/

CustomerList::CustomerList()
{
   cust_size=0;
   cust_head=NULL;
}
CustomerList::  CustomerList ( const CustomerList & copyCustList){
    //Copy the size
    cust_size=copyCustList.cust_size;
//Check if the list to be copied is empty
if(copyCustList.cust_head==NULL){
    cust_head=NULL;
}
else{
    // copy first node
      cust_head = new CustomerNode;
      cust_head->random_customer = copyCustList.cust_head->random_customer;
      // copy rest of the  list
      CustomerNode *newPtr = cust_head;
      for (CustomerNode *tempPointer = copyCustList.cust_head->cust_next;
                     tempPointer != NULL;
                     tempPointer = tempPointer->cust_next){
         newPtr->cust_next = new CustomerNode;
         newPtr = newPtr->cust_next;
         newPtr->random_customer = tempPointer->random_customer;
      }
      newPtr->cust_next = NULL;
   }
}
CustomerList::~CustomerList()
{
    //cout<<"destructo customerlist"<<endl;
    while(!cust_isEmpty()){
        cust_remove(1);
    }
}

//Implementation of the methods
bool CustomerList:: cust_isEmpty() const {
 return cust_size==0;   //if size is 0 it means that is empty,otherwise not empty
}
int CustomerList:: cust_getLength() const {
    return cust_size;  //return the length of the list.Length is kept as a variable
}
//this is an internal method which finds a certain node by traversing until the required index
CustomerList::CustomerNode *CustomerList::cust_find ( int index) const {
    if ( (index < 1) || (index > cust_getLength()))
      return NULL;
    else {
       CustomerNode * temp=cust_head;
       for (int counter =1 ; counter<index;++counter){
          temp= temp->cust_next;
       }
       return temp;
    }
}
 bool CustomerList:: cust_retrieve(int index,Customer &to_retrieve) const {
    if ((index < 1) || (index > cust_getLength()))
      return false;
    //Point the node to a temp node pointer.Then copy the data members
   CustomerNode *temp = cust_find(index);
   to_retrieve=temp->random_customer;
   //By this the operation result should be true in any case
   return true;

}
bool CustomerList:: cust_insert(int index, Customer toAdd){
    int cust_new_size = 1+ cust_getLength();
    //Check for index exceptions
    if ((index < 1) || (index > cust_new_size))
      return false;

   CustomerNode *newPtr = new CustomerNode;
   cust_size = cust_new_size;
   newPtr->random_customer=toAdd;
   if(index==1){
    newPtr->cust_next=cust_head;
    cust_head=newPtr;
   }
   else {
    CustomerNode *previous = cust_find(index-1);
    newPtr->cust_next=previous->cust_next;
    previous->cust_next=newPtr;
   }
   return true;

}
bool CustomerList:: cust_remove(int index){
    CustomerNode *temp;
    //Firstly we check for index errors
    if ((index < 1) || (index > cust_getLength()))
      return false;

  --cust_size;  //decrease the size
 //check for whether the node to be deleted is the head
 if(index ==1){
    temp=cust_head;
    cust_head=cust_head->cust_next;
 }else {
     CustomerNode *before = cust_find(index-1);
     temp=before->cust_next;
     before->cust_next=temp->cust_next;
 }
 temp->cust_next=NULL;
 delete temp;
 temp=NULL;
 return true;

}
