#include "Car.h"

Car::Car(std:: string id, float price, unsigned int seats): m_id{id}, m_price{price} , m_seat_count{seats}{

}
float Car:: InsuranceAmount(){return 0.2f * m_price;};