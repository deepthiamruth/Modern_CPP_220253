#ifndef DEBITCARD_H
#define DEBITCARD_H
#include<iostream>
#include "DebitCardType.h"

class DebitCard{
    private:
    short m_card_cvv{-1};
    std::string m_card_expiry_date{""};
    long long m_card_number{0};
    DebitCardType m_card_type{DebitCardType:: VISA};
    public:

    DebitCard() = default;
    DebitCard(const DebitCard& other) = default; //copy
    DebitCard(DebitCard && other) = delete; //move
    DebitCard& operator= (const DebitCard& other) = delete; // 
    DebitCard& operator = (DebitCard&& other) = delete;
    ~DebitCard();


    DebitCard(short cvv, std::string expirydate , long long number , DebitCardType type);
    

    short getcardCvv() const { return m_card_cvv; }
    void setCardCvv(short card_cvv) { m_card_cvv = card_cvv; }

    std::string getcardExpiryDate() const { return m_card_expiry_date; }
    void setCardExpiryDate(const std::string &card_expiry_date) { m_card_expiry_date = card_expiry_date; }

    long long getcardNumber() const { return m_card_number; }
    void setCardNumber(long long card_number) { m_card_number = card_number; }

    DebitCardType getcardType() const { return m_card_type; }
    void setCardType(const DebitCardType &card_type) { m_card_type = card_type; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
    
};

#endif 

