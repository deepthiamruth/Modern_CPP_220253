#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "BankAccount.h"
#include "AccountNotFoundException.h"

#include<vector>
using container = std::vector <BankAccount* > ;
void CreateObjects( container &, unsigned int size);
void DisplayDetails(std:: vector<BankAccount*>, unsigned int size ,long number);
void CountVisaCards( container&  , unsigned int size);


#endif // FUNCTIONALITIES_H
