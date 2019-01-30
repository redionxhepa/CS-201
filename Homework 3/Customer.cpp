#include "Customer.h"
#include "AccountList.h"
/*
Student:Redion Xhepa
ID:21500280
This is the implementation of the customer class.This implementation is needed since
we need to store the data in the CustomerNodes as Customer object(OOP)

*/

Customer::Customer()
{

        id_cust=0;
         name_cust="empty";
        last_name_cust="empty";
       // accounts=NULL;
       //Implicitly accounts is started to zero
}

Customer:: Customer( const Customer & copyCust){

       id_cust= copyCust.id_cust;
       name_cust=copyCust.name_cust;
       last_name_cust= copyCust.last_name_cust;
       accounts=copyCust.accounts;
}
Customer::~Customer()
{
   // if(accounts!=NULL) {
   //     delete accounts;
   // }
   // cout<<"you have just deleted the client with ID : "<<id_cust<<endl;
}

//Implementation of the methods
 AccountList * Customer:: return_accountList() {
     return  &accounts;

 }

 void Customer:: setId(int a){
     this->id_cust=a;
 }
int Customer:: getId(){
    return this->id_cust;
}

void Customer:: set_name (string b){
  this->name_cust=b;
}
string Customer:: get_name(){
    return this->name_cust;
}
void Customer:: set_last_name (string c) {
  this->last_name_cust=c;
}
string Customer:: get_last_name(){
 return this->last_name_cust;
}


