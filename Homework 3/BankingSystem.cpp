#include "BankingSystem.h"
#include "CustomerList.h"
#include "Customer.h"
#include "AccountList.h"
#include "Account.h"

#include <iostream>
#include<string>
using namespace std;
/*

This is the implementation of the banking system.
*/

BankingSystem::BankingSystem()
{
 cout<<"you created an empty banking system"<<endl;
 noOfTotalAccounts=0;
// cout<<customers.cust_getLength()<<endl;
}

BankingSystem::~BankingSystem()
{
cout<<"The bank is destroyed"<<endl;
}
//Full working method that adds the customers and sorts them according to the surname(if same according to the names)
void BankingSystem:: addCustomer( const int customerId, const string firstName, const string lastName ){

    //Create the new Customer object
    Customer tobeAdded;
    tobeAdded.setId(customerId);
    tobeAdded.set_name(firstName);
    tobeAdded.set_last_name(lastName);

    //Try to add the new customer,check for inconsistencies
    if(customers.cust_getLength()==0){

      customers.cust_insert(1,tobeAdded);
      cout<<"Customer "<<tobeAdded.getId()<<"  has been added"<<endl;
     // cout<<"Type0"<<endl;
    }
    else {
        for(int i=1;i<=customers.cust_getLength();i++){
            Customer temp ;
            customers.cust_retrieve(i,temp);
            if(temp.getId()==tobeAdded.getId()){
                cout<<"Error! This ID is previously occupied.You cannot use this id"<<endl;
                return;
            }else if (temp.get_name()==tobeAdded.get_name() && temp.get_last_name()==tobeAdded.get_last_name()){
                cout<<"This person cannot be added.This person currently exists"<<endl;
                return;
            }else  {
              if(isBeforeLex(tobeAdded.get_last_name(),temp.get_last_name())==true && temp.getId()!=tobeAdded.getId()){

                  customers.cust_insert(i,tobeAdded);
                  cout<<"Customer "<<tobeAdded.getId()<<"  has been added"<<endl;
                // cout<<"Type 1"<<endl;
                  return;
              }else if(tobeAdded.get_last_name()==temp.get_last_name()&& temp.getId()!=tobeAdded.getId()){

                if(isBeforeLex(tobeAdded.get_name(),temp.get_name())==true && temp.getId()!=tobeAdded.getId()){

                  customers.cust_insert(i,tobeAdded);
                  cout<<"Customer "<<tobeAdded.getId()<<"  has been added"<<endl;
                //  cout<<"Type 2"<<endl;

                 return;
                }else{

                     customers.cust_insert(i+1,tobeAdded);
                     cout<<"Customer "<<tobeAdded.getId()<<"  has been added"<<endl;
                  //   cout<<"Type 3"<<endl;
                     return;

                }
              }
            }

        }
    }

}
//Full working method which deletes the customer when given the id of the customer(if it is found)
void BankingSystem:: deleteCustomer( int customer_Id ) {
  Customer iterator_customer;
    bool found=false;
    if (customers.cust_getLength()==0){
        cout<<"You cannot delete ! Please check your operation"<<endl;

    }else {
        for(int i=1;i<=customers.cust_getLength();i++){

            customers.cust_retrieve(i,iterator_customer);
            if(iterator_customer.getId()==customer_Id){
                found=true;
                 //Deleting the accounts of the user is missing
                customers.cust_remove(i);
                cout<<"Customer with ID: " <<customer_Id<< " is deleted "<<endl;
            }
    }
     if(found==false){
        cout<<"Please check your operation!Id not found "<<endl;
     }
    }
}


int BankingSystem::addAccount( int customer_Id, double amount ){
    bool found = false;
    Customer iterator_customer;
    Account toEnter;
    int length_acc_2;
    if (customers.cust_getLength()==0){
            cout<<"here 1"<<endl;
        cout<<"You cannot add the account! Please check your operation"<<endl;
        return -1;
    }
    else {
        if(iterator_customer.return_accountList()->acc_getLength()==0){
                noOfTotalAccounts++;
            toEnter.setId(noOfTotalAccounts);
            toEnter.set_amount(amount);
          iterator_customer.return_accountList()->acc_insert(1,toEnter);
          return noOfTotalAccounts;
         //  cout<<"Customer "<<tobeAdded.getId()<<"  has been added"<<endl;
          // cout<<"Type0"<<endl;
        }

        for(int i=1;i<=customers.cust_getLength();i++){
            customers.cust_retrieve(i,iterator_customer);
            if(iterator_customer.getId()==customer_Id){
                    found=true;
                    //the new account to be inserted in the relevant list for the pertaining customer
                    noOfTotalAccounts++; //keeps track of the number of the accounts and therefore serves as account ID
                    toEnter.setId(noOfTotalAccounts);
                    toEnter.set_amount(amount);
                    //Find the length and use it as the index
                    cout<<"here"<<endl;
                   length_acc_2=iterator_customer.return_accountList()->acc_getLength();
                    cout<<"entered before insert"<<endl;
                   iterator_customer.return_accountList()->acc_insert(length_acc_2+1,toEnter);
               //    cout<<iterator_customer.return_accountList()->acc_getLength()<<" size 2"<<endl;
                   // iterator_customer.return_accountList()->printAccounts();
                   //Now the account has been entered;
                  return noOfTotalAccounts ;//the id

            }
        }
        if(found==false){
                 cout<<"You cannot add the account! Please check your operation"<<endl;
                 return -1;
        }
    }
}

void  BankingSystem:: deleteAccount(  int accountId ){
    bool deleted=false;
    if (customers.cust_getLength()==0){
            cout<<"here 1"<<endl;
        cout<<" Please check your operation! You cannot delete something that is not there"<<endl;
        return;
    }else {
        Customer cust_it;
        for(int i=1;i<=customers.cust_getLength();i++){
                customers.cust_retrieve(i,cust_it);
                if(cust_it.return_accountList()->acc_isEmpty()==false){
                    for(int j=1;j<=cust_it.return_accountList()->acc_getLength();j++){
                        Account temp;
                        cust_it.return_accountList()->acc_retrieve(i,temp);
                       // cust_it.acc_retrieve(i,temp);
                        if(temp.getId()==accountId){
                                deleted=true;
                            cust_it.return_accountList()->acc_remove(i);
                             return;
                        }
                    }
                }

        }

    }
     if(deleted==false){
        cout<<"Operation cannot be completed"<<endl;
        return;
     }

}



//Finished and tested method which shows all the customers
void BankingSystem:: showAllCustomers() {
    if(customers.cust_getLength()==0){
        cout<<"Empty! There is no customer"<<endl;
    }else{
        for(int i =1;i<=customers.cust_getLength();i++){
            Customer random_cust;
            customers.cust_retrieve(i,random_cust);
            cout<<"ID is : "<<random_cust.getId()<<" " <<random_cust.get_name()<<" "<<random_cust.get_last_name()<<endl;
        }
    }
}
void BankingSystem:: showAllAccounts() {
    if(customers.cust_getLength()==0){
        cout<<"Empty! There is no customer ,so there is no accounts"<<endl;
    }else{
        for(int i =1;i<=customers.cust_getLength();i++){
                cout<<"Account ID      Customer ID         Customer Name          Balance "<<endl;
                Customer random_cust;
                customers.cust_retrieve(i,random_cust);
                if(random_cust.return_accountList()->acc_isEmpty()==false){ //meaning for all the customers which have at least one account
                    for(int j=1;j<=random_cust.return_accountList()->acc_getLength();j++){
                        Account temporary;
                        random_cust.return_accountList()->acc_retrieve(j,temporary);
                    cout<< temporary.getId()<< "    " <<random_cust.getId()<< "      " <<random_cust.get_name()<< " "<<random_cust.get_last_name()<< "    "<<temporary.get_amount() <<endl;

                    }
                }

        }
    }
}

void BankingSystem:: showCustomer(  int customerId ) {
    bool found=false;
    if(customers.cust_getLength()==0){
        cout<<"Empty! There is no customer ! Check your operations!"<<endl;
    }else{
      for(int i=1 ;i<=customers.cust_getLength();i++){
        Customer random_custo;
        customers.cust_retrieve(i,random_custo);
        if(random_custo.getId()==customerId){
                found=true;
            cout<<"Account ID: "<<random_custo.getId()<<"  Customer : " <<random_custo.get_name()<<"  "<<random_custo.get_last_name()<<"   Account n.o "<<random_custo.return_accountList()->acc_getLength()<<endl;
            return;
        }


      }
    }
    if(found==false){
        cout<<"The operation cannot be carried out.Invalid customer ID number! Check your input! "<<endl;
    }

}

bool BankingSystem:: isBeforeLex(string a, string b){
  int i=0;
  bool isBefore=false;
  while(i<a.length() && i<b.length())  {
    if(a[i]<b[i]) {
         isBefore=true;
         break;

    }else if (a[i]>b[i]){

         isBefore=false;
         break;
    } else{
        i++;
    }
    if(a.length()<b.length()){
        isBefore=true;  //for the cases such as "redio" and "redion"
    }

  }
    return isBefore;
}

CustomerList* BankingSystem:: returnCustomerListOfBank() {
  return &customers;
}
