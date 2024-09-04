#include "CommercialVehicle.h"

CommercialVehicle::CommercialVehicle(std::string number, float price, unsigned int age, std::shared_ptr<Permit> permit)
:m_reg_number{number}, m_price{price}, m_vehicle_age{age}, m_permit{permit}
{
}

float CommercialVehicle::CalculateRTOCharges()
{
    return 0.10f * m_price;
}
