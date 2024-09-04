#include "Permit.h"

Permit::Permit(std::string permit_number, float charges, ChassisType type)
: m_permit_reg_number{permit_number}, m_annual_renewal_charges{charges}, m_chassis_type{type}
{
}