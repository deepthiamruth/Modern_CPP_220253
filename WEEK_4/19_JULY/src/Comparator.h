#ifndef COMPARATOR_H
#define COMPARATOR_H
#include<memory>
#include "Vehicle.h"

using VehicleSptr = std::shared_ptr<Vehicle>;
struct Comparator{
    bool operator()(const VehicleSptr& v1, const VehicleSptr& v2){
        return v1->getvehiclePrice() < v2->getvehiclePrice();
    }
    Comparator() = default;
    ~Comparator() = default;
};

#endif // COMPARATOR_H


//g++ -c functionalities.cpp 