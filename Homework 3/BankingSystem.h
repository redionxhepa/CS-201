#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H
#include "CustomerList.h"
#include "CustomerList.h"
#include "Account.h"
#include "AccountList.h"
#include "Customer.h"
#include <iostream>
#include<string>
using namespace std;




class BankingSystem {
public:
BankingSystem();
~BankingSystem();
void addCustomer( const int customerId, const string firstName, const string lastName );
void deleteCustomer( const int customerId );
int addAccount( const int customerId, const double amount );
void deleteAccount( const int accountId );
void showAllAccounts();
void showAllCustomers();
void showCustomer( const int customerId );
bool isBeforeLex(string a, string b); //Used to compare lexicographically the names and the last names
CustomerList* returnCustomerListOfBank();


private:
    CustomerList  customers;
    int noOfTotalAccounts;

};

#endif // BANKINGSYSTEM_H
