#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include <iostream>
#include "Account.h"
#include<string>
using namespace std;

class AccountList
{
    public:
        AccountList();
        virtual ~AccountList();
        AccountList( const AccountList & copyList);
        void operator=(const AccountList &tocopy);
       //List of the methods
        bool acc_isEmpty() const  ;
        int acc_getLength() const ;
        bool  acc_retrieve(int index,Account & account_retrieve) const ;
        bool  acc_insert(int index, Account to_be_entered);
        bool acc_remove(int index);
        void printAccounts();

        //Definition of the node
        private:
        struct AccountNode{
            Account random_account;
            AccountNode * acc_next;
        };
        AccountNode* acc_find( int index) const;
        int acc_size;
        AccountNode *acc_head;
};

#endif // ACCOUNTLIST_H
