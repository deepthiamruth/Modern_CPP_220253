#include "Functionalities.h"
 void CreateObjects(container& accounts  , const unsigned int size){
   
    accounts.emplace_back(new BankAccount(67895454, "deepthi", 7865.0f, BankAccountType::CURRENT, new DebitCard(123, "12/12", 765675, DebitCardType::AMEX)));
    accounts.emplace_back(new BankAccount(67895454, "deepthi", 7865.0f, BankAccountType::CURRENT, new DebitCard(123, "12/12", 765675, DebitCardType::AMEX)));
    accounts.emplace_back(new BankAccount(67895454, "deepthi", 7865.0f, BankAccountType::CURRENT, new DebitCard(123, "12/12", 765675, DebitCardType::AMEX)));


 }
/*
    A function to find and display the details of debitcard for account whose number is provided as parameter
*/
void DisplayDetails(std:: vector<BankAccount*> accounts, unsigned int size ,long number){
    bool flag = false;
    for(BankAccount* b : accounts){
        if(b && number == b->getaccountNumber() ){
            std:: cout << b->getattachedCard() <<"\n";
            flag = true;
            break;
        }
    }
    if(!flag){
        throw AccountNotFoundException("Invalid number");
    }
}
/*
    Find and display the count of Debitcard of type visa
*/
void CountVisaCards( container& accounts , unsigned int size){
    unsigned int count =0;
    for(unsigned int i=0 ;i<size;i++){
        /*
            if i position finds debitcard and then checks type of debit card if we find visa increase count by 1
        */
        if(accounts[i]->getattachedCard()->getcardType()==DebitCardType::VISA){
            count++;
        }
    }
    std::cout <<"Count is :"<< count <<"\n";
}

void DeleteObjects(container & accounts, unsigned int size){
    for(BankAccount * b : accounts){
        delete b;
    }
}