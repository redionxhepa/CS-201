#include "Account.h"
#include <iostream>
#include<string>
using namespace std;

Account::Account( )
{

    id_acc=0;
    amount_acc=0;
}

 Account::Account( const Account & copyAccount){

  id_acc=copyAccount.id_acc;
  amount_acc=copyAccount.amount_acc;
}

Account::~Account()
{
    //Is empty since there will be no dynamic memory used
   // cout<<"Account with no " <<id_acc<<" has been deleted"<<endl;
}

//Setter and getter methods
 void Account:: setId(int k){
     id_acc=k;
 }
int Account:: getId(){
    return id_acc;
}
void Account:: set_amount(double a ){
    amount_acc=a;
}
double Account:: get_amount(){
    return amount_acc;
}

