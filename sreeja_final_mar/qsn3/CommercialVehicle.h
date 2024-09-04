#ifndef COMMERCIALVEHICLE_H
#define COMMERCIALVEHICLE_H

#include <iostream>
#include <memory>
#include <functional>

#include "Permit.h"


class CommercialVehicle
{
private:
    std::string m_reg_number {""};
    float m_price {0.0f};
    unsigned int m_vehicle_age {0};
    std::shared_ptr<Permit> m_permit;

public:
    CommercialVehicle() = default;
    ~CommercialVehicle() = default;
    CommercialVehicle(const CommercialVehicle& ) = default;
    CommercialVehicle(CommercialVehicle&& ) = delete;
    CommercialVehicle& operator = (const CommercialVehicle& ) = delete;
    CommercialVehicle& operator = (CommercialVehicle&& ) = delete;

    CommercialVehicle(std::string number, float price, unsigned int age, std::shared_ptr<Permit> permit);

    float CalculateRTOCharges();

    std::string regNumber() const { return m_reg_number; }

    float price() const { return m_price; }

    unsigned int vehicleAge() const { return m_vehicle_age; }

    std::shared_ptr<Permit> permit() const { return m_permit; }

    friend std::ostream &operator<<(std::ostream &os, const CommercialVehicle &rhs) {
        os << "m_reg_number: " << rhs.m_reg_number
           << " m_price: " << rhs.m_price
           << " m_vehicle_age: " << rhs.m_vehicle_age
           << " m_permit: " << &rhs.m_permit;
        return os;
    }

};



#endif // COMMERCIALVEHICLE_H
