#include "Vehicle.h"

float Vehicle::CalculateRegistrationCost() const
{
    float ans{0.0f};
    if(m_vehicle_fuel_type == FuelType::ICE || m_vehicle_fuel_type == FuelType::ALTERNATE_FUEL){
        ans= 0.1f* m_vehicle_price;
    }
    else{
        ans=0.2f* m_vehicle_price;
    }
    return ans; //MISRA C 
}

Vehicle::Vehicle(StandardType standards, FuelType fuel, EngineType engine, MultimediaType media, float price): m_vehicle_standard{standards}, m_vehicle_fuel_type{fuel}, m_vehicle_engine_type{engine}, m_vehicle_multimedia_type{media}, m_vehicle_price{price}
{
    if(m_vehicle_fuel_type == FuelType::ALTERNATE_FUEL){
        m_vehicle_engine_type = EngineType::NA;
    }
}
