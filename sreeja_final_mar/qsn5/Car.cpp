#include "Car.h"

Car::Car(std::string id, unsigned int category, float length, CarType cartype, float seatcount)
: m_reg_id{id}, m_emmison_category{category}, m_chassis_length{length}, m_carType{cartype}, m_seatCount{seatcount}
{
    
}