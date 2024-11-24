#include "DebitCard.h"
 std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
        os << "m_card_cvv: " << rhs.m_card_cvv
           << " m_card_expiry_date: " << rhs.m_card_expiry_date
           << " m_card_number: " << rhs.m_card_number
           << " m_card_type: " << rhs.m_card_type;
        return os;
}

DebitCard::~DebitCard()
{
   
}

DebitCard::DebitCard(short cvv, std::string expirydate, long long number, DebitCardType type) : m_card_cvv{cvv}, m_card_expiry_date{expirydate}, m_card_number{number}, m_card_type{type}
{
}
