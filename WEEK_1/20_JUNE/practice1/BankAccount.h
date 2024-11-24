#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "BankAccountType.h"
#include "DebitCard.h"
#include<iostream>

class BankAccount{
    private:
    long m_accountNumber{-1};
    std::string m_accountHolderName{""};
    float m_accountBalance{0.0f};
    BankAccountType m_accountType{BankAccountType::CURRENT};
    DebitCard* m_attached_card{};
    public:
     BankAccount() = default;
    BankAccount(const BankAccount& other) = delete;
    BankAccount& operator= (const BankAccount& other) = delete;
    BankAccount(BankAccount && other) = delete;
    BankAccount& operator = (BankAccount&& other) = delete;
    BankAccount(long number, std:: string name, float balance, BankAccountType type, DebitCard *debit);

    ~BankAccount();

    long getaccountNumber() const { return m_accountNumber; }
    void setAccountNumber(long accountNumber) { m_accountNumber = accountNumber; }

    std::string getaccountHolderName() const { return m_accountHolderName; }
    void setAccountHolderName(const std::string &accountHolderName) { m_accountHolderName = accountHolderName; }

    float getaccountBalance() const { return m_accountBalance; }
    void setAccountBalance(float accountBalance) { m_accountBalance = accountBalance; }

    BankAccountType getaccountType() const { return m_accountType; }
    void setAccountType(const BankAccountType &accountType) { m_accountType = accountType; }

    DebitCard* getattachedCard() const { return m_attached_card; }
    void setAttachedCard(DebitCard* attached_card) { m_attached_card = attached_card; }

    // DebitCard getattachedCard() const { return *m_attached_card; }
    // void setAttachedCard(const DebitCard* &attached_card) { m_attached_card* = attached_card; }

  

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs);
};


#endif // BANKACCOUNT_H