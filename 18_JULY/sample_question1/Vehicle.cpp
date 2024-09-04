#include "Vehicle.h"

float Vehicle::CalculateRegistrationCost()
{
    if(m_vehicle_fuel_type == FuelType::ICE || m_vehicle_fuel_type == FuelType::ALTERNATE_FUEL){
        return 0.10* m_vehicle_price;
    }
    else{
        return 0.20* m_vehicle_price;
    }
    return 0.0f;
}

Vehicle::Vehicle(StandardType standards, FuelType fuel, EngineType engine, MultimediaType media, float price): m_vehicle_standard{standards}, m_vehicle_fuel_type{fuel}, m_vehicle_engine_type{engine}, m_vehicle_multimedia_type{media}, m_vehicle_price{price}
{

}
