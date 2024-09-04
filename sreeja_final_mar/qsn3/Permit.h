#ifndef PERMIT_H
#define PERMIT_H

#include <iostream>

#include "ChassisType.h"

class Permit
{
private:
    std::string m_permit_reg_number {""};
    float m_annual_renewal_charges {0.0f};
    ChassisType m_chassis_type {ChassisType::LEASE};

public:
    Permit() = default;
    ~Permit() = default;
    Permit(const Permit&) = default;
    Permit(Permit&&) = default;
    Permit& operator = (const Permit&) = delete;
    Permit& operator = (Permit&&) = delete;
    
    Permit(std::string permit_number, float charges, ChassisType type);

    std::string permitRegNumber() const { return m_permit_reg_number; }

    float annualRenewalCharges() const { return m_annual_renewal_charges; }

    ChassisType chassisType() const { return m_chassis_type; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
        os << "m_permit_reg_number: " << rhs.m_permit_reg_number
           << " m_annual_renewal_charges: " << rhs.m_annual_renewal_charges
           << " m_chassis_type: " << (int) rhs.m_chassis_type;
        return os;
    }
};



#endif // PERMIT_H
