#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include "AccountList.h"
#include "Customer.h"
#include <iostream>
#include<string>
using namespace std;



class CustomerList
{
    public:
        CustomerList();
        CustomerList( const CustomerList & copyCustList);
        virtual ~CustomerList();
        bool cust_isEmpty() const;
       int cust_getLength() const;
       bool cust_retrieve(int index,Customer & customer_retrieve) const;
       bool cust_insert(int index,Customer customer_to_add);
       bool cust_remove(int index);

    private:
        struct CustomerNode{
           Customer random_customer;
           CustomerNode *cust_next;
        };
    int cust_size;
    CustomerNode *cust_head;
    CustomerNode* cust_find( int index) const;


};

#endif // CUSTOMERLIST_H
