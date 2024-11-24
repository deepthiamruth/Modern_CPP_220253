#include "BankAccount.h"
std::ostream &operator<<(std::ostream &os, const BankAccount &rhs) {
        os << "m_accountNumber: " << rhs.m_accountNumber
           << " m_accountHolderName: " << rhs.m_accountHolderName
           << " m_accountBalance: " << rhs.m_accountBalance
           << " m_accountType: " << rhs.m_accountType
           << " m_attached_card: " << rhs.m_attached_card;
        return os;
    }
BankAccount:: BankAccount (long number , std::string name, float balance, BankAccountType type, DebitCard* debit): m_accountNumber {number} ,  m_accountHolderName{name}, m_accountBalance{balance}, m_accountType{type}, m_attached_card{debit}{

}
BankAccount :: ~BankAccount (){
    delete m_attached_card;
}