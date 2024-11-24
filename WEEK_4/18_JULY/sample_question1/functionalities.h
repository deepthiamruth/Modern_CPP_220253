#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include<memory>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using pointer = std::shared_ptr<Vehicle>;
using DataContainer = std::vector<pointer>;
using Predicate1 = std::function<bool(DataContainer)>;

extern auto fn = [](const Vehicle& e1, const Vehicle& e2){return e1.getvehiclePrice() < e2.getvehiclePrice();};

using hash_fn = std::function<std::size_t(pointer)>;


//A function to create 5 objects of Vehicle class on the heap. Each object must be managed by a shared_ptr. The objects must be stored in a vector container.
void CreateObjects(DataContainer&);



//A function to return a priority queue of all smart pointers in the data container where max priority is given to Vehicle with highest m_vehicle_price
std::priority_queue<pointer, DataContainer, decltype(fn)> CreatePriorityQueue(const DataContainer&);



//A function to return one vehicle of each m_vehicle_multimedia_type category from the data container. 
//Hint: If there are 5 objects with types ANALOG, ANDROID_SMART, APPLE_SMART, ANALOG and ANDROID_SMART, return the first 3 objects only (unique category objects)
//[Hint: Create an unordered_set]
pointer CreateUnordered_set(const DataContainer&);



//A function to find the count of Vehicle objects whose m_vehicle_engine_type matches the m_vehicle_engine_type value given by the user
std::optional <unsigned int> count_vehicles(DataContainer& , EngineType );



// A function to check if all vehicles have price above 90000.0f or not
std::optional<bool> CheckPrice(DataContainer& );



//A function to return a vector of instances which satisfy the predicate passed as a parameter while calling the function
std::optional<DataContainer> CopyVehicles(DataContainer& );



//A function to find the average of CalculateRegistrationCost function value
float accumulateData(const DataContainer&);



//A function to return a vector of instances which satisfy the predicate passed as a parameter while calling the function
std::optional<DataContainer> CopyVehicles(DataContainer&);


#endif // FUNCTIONALITIES_H
