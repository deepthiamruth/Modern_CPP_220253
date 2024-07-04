#include "Bike.h"

Bike:: Bike(std:: string id, float price): m_id{id}, m_price{price}{

}
float Bike:: InsuranceAmount(){return 0.1f * m_price;};