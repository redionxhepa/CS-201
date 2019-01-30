#include "AccountList.h"
#include "Account.h"
#include <iostream>
#include<string>
using namespace std;

/*

This is the implementation of a list containing account objects.The idea(construction) is based upon the slides

*/
AccountList::AccountList()
{
   acc_size=0;
   acc_head=NULL;

}

AccountList::AccountList( const AccountList & copyList) {
    //Copy at first the size
    acc_size=copyList.acc_size;
//Check if the list to be copied is empty
if(copyList.acc_head==NULL){
    acc_head=NULL;
}
else{
    // copy first node
      acc_head = new AccountNode;
      acc_head->random_account = copyList.acc_head->random_account;
      // copy rest of the  list
      AccountNode *newPtr = acc_head;
      for (AccountNode *tempPointer = copyList.acc_head->acc_next;
                     tempPointer != NULL;
                     tempPointer = tempPointer->acc_next){
         newPtr->acc_next = new AccountNode;
         newPtr = newPtr->acc_next;
         newPtr->random_account = tempPointer->random_account;
      }
      newPtr->acc_next = NULL;
   }
}

AccountList::~AccountList()
{
   // cout<<"destructor accountlist"<<endl;
    while(!acc_isEmpty()){
        acc_remove(1);
    }
}

//Implementation of the methods

void AccountList::operator=(const AccountList &copyList){

	if(copyList.acc_head==NULL){
		acc_head = NULL;
	}
	else{

      acc_head = new AccountNode;
      acc_head->random_account = copyList.acc_head->random_account;
      // copy rest of the  list
      AccountNode *newPtr = acc_head;
      for (AccountNode *tempPointer = copyList.acc_head->acc_next;
                     tempPointer != NULL;
                     tempPointer = tempPointer->acc_next){
         newPtr->acc_next = new AccountNode;
         newPtr = newPtr->acc_next;
         newPtr->random_account = tempPointer->random_account;
      }
      newPtr->acc_next = NULL;
   }
}

bool AccountList:: acc_isEmpty() const {
 return acc_size==0;   //if size is 0 it means that is empty,otherwise not empty
}
int AccountList:: acc_getLength() const {
    return acc_size;  //return the length of the list.Length is kept as a variable
}
//this is an internal method which finds a certain node by traversing until the required index
AccountList::AccountNode *AccountList::acc_find ( int index) const {
    if ( (index < 1) || (index > acc_getLength()))
      return NULL;
    else {
       AccountNode * temp=acc_head;
       for (int counter =1 ; counter<index;++counter){
          temp= temp->acc_next;
       }
       return temp;
    }
}
 bool AccountList:: acc_retrieve(int index,Account & account_retrieve) const {
    if ((index < 1) || (index > acc_getLength()))
      return false;
    //Point the node to a temp node pointer.Then copy the data members
   AccountNode *temp = acc_find(index);
   account_retrieve=temp->random_account;
   //By this the operation result should be true in any case
   return true;
}
bool AccountList:: acc_insert(int index, Account to_be_entered){

    int acc_new_size = 1+ acc_getLength();
    //Check for index exceptions
    if ((index < 1) || (index > acc_new_size))

      return false;

   AccountNode *newPtr = new AccountNode;
   acc_size = acc_new_size;
   newPtr->random_account=to_be_entered;
   //cout<<acc_size <<"  Size "<<endl;

   if(index==1){

        //cout<<"it means it is the first one"<<endl;
    newPtr->acc_next=acc_head;
    acc_head=newPtr;
   }
   else {
      // cout<<"It means is not the first one"<<endl;
    AccountNode *previous = acc_find(index-1);
    newPtr->acc_next=previous->acc_next;
    previous->acc_next=newPtr;
   }
   //Now the new node is inserted
  // cout<<"step1"<<endl;
   // cout<<acc_size <<"  Size "<<endl;
   return true;

}
bool AccountList:: acc_remove(int index){
    AccountNode *temp;
    //Firstly we check for index errors
    if ((index < 1) || (index > acc_getLength()))
      return false;

  --acc_size;  //decrease the size
 //check for whether the node to be deleted is the head
 if(index ==1){
    temp=acc_head;
    acc_head=acc_head->acc_next;
 }else {
     AccountNode *before = acc_find(index-1);
     temp=before->acc_next;
     before->acc_next=temp->acc_next;
 }
 temp->acc_next=NULL;
 delete temp;
 temp=NULL;
 return true;

}
void AccountList:: printAccounts(){
    if(acc_isEmpty()==true){
        cout<<"Empty Account List"<<endl;
    } else{
        for(int i =1; i<=acc_getLength();i++){

                Account temp;
                acc_retrieve(i,temp);
                cout<<"Id is "<<temp.getId()<<" amount is "<<temp.get_amount()<<endl;

        }
    }
}
