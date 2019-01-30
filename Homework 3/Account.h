#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include<string>
using namespace std;

class Account
{

    public:
        Account();
        Account( const Account & copyAccount);
        virtual ~Account();
        //Setters and getters
        void setId(int);
        int  getId();
        void set_amount(double );
        double get_amount();
        int  get_count_id();



    private:
        static int count_id ;
        int id_acc;
        double amount_acc;
};

#endif // ACCOUNT_H
