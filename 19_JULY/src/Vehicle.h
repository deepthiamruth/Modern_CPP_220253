#ifndef VEHICLE_H
#define VEHICLE_H
#include "Enums.h"
#include<iostream>

class Vehicle{
private:
    enum StandardType m_vehicle_standard{StandardType::BS4};
    enum FuelType m_vehicle_fuel_type{FuelType::ALTERNATE_FUEL};
    enum EngineType m_vehicle_engine_type{EngineType::NA};
    enum MultimediaType m_vehicle_multimedia_type{MultimediaType::ANALOG};
    float m_vehicle_price{0.0f};
public:
    Vehicle() = default;
    ~Vehicle() = default;
    Vehicle(const Vehicle&) = default;
    Vehicle(Vehicle&&) = delete;
    Vehicle& operator=(const Vehicle&) = default;
    Vehicle& operator=(Vehicle&&) = delete;

    //function to find registration cost
    float CalculateRegistrationCost() const; //this fun is valid for const object

    Vehicle(StandardType standards, FuelType fuel,EngineType engine, MultimediaType media, float price);

    //getters for data members
    enum StandardType getvehicleStandard() const { return m_vehicle_standard; }
    enum FuelType getvehicleFuelType() const { return m_vehicle_fuel_type; }
    enum EngineType getvehicleEngineType() const { return m_vehicle_engine_type; }
    enum MultimediaType getvehicleMultimediaType() const { return m_vehicle_multimedia_type; }
    float getvehiclePrice() const { return m_vehicle_price; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
        os << "m_vehicle_standard: " << (int)rhs.m_vehicle_standard
           << " m_vehicle_fuel_type: " << (int)rhs.m_vehicle_fuel_type
           << " m_vehicle_engine_type: " << (int)rhs.m_vehicle_engine_type
           << " m_vehicle_multimedia_type: " << (int)rhs.m_vehicle_multimedia_type
           << " m_vehicle_price: " << rhs.m_vehicle_price;
        return os;
    }
};

#endif // VEHICLE_H
