#ifndef CUSTOMER_H
#define CUSTOMER_H

/*
Student:Redion Xhepa
ID:21500280
This is the implementation of the customer class.This implementation is needed since
we need to store the data in the CustomerNodes as Customer object(OOP)

*/

#include "AccountList.h"
class Customer
{
    public:
        Customer();
        Customer( const Customer & copyCust);
        virtual ~Customer();

         //Setters and getters
        void setId(int);
        int  getId();
        void set_name (string);
        string get_name();
        void set_last_name (string);
        string get_last_name();
        AccountList * return_accountList();

    private:
        int id_cust;
        string name_cust;
        string last_name_cust;
        AccountList accounts;
};

#endif // CUSTOMER_H
