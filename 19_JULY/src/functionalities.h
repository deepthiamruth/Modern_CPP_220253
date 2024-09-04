#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include<memory>
#include<vector>
#include<queue>
#include<optional>
#include<algorithm>
#include<functional>
#include<numeric>
#include "Comparator.h"
#include<unordered_set>
#include<future>

using VehicleSptr = std::shared_ptr<Vehicle>;
using DataContainer = std::vector<VehicleSptr>;
using Predicate1 = std::function<bool(const VehicleSptr)>;
using PriorityQ = std::priority_queue<VehicleSptr, DataContainer, Comparator>;



//////////////////////////////////////////////////////////////////////////////////////////

//A function to create 5 objects of Vehicle class on the heap. Each object must be managed by a shared_ptr. The objects must be stored in a vector container.
void CreateObjects(DataContainer&);


//A function to return a priority queue of all smart VehicleSptrs in the data container where max priority is given to Vehicle with highest m_vehicle_price
PriorityQ PrioritizeVehicles(const DataContainer&);



//A function to find the count of Vehicle objects whose m_vehicle_engine_type matches the m_vehicle_engine_type value given by the user
std::optional<std::size_t> CountMatchingEngineTypeVehicle(const DataContainer& ,const EngineType );



//A function to return a vector of instances which satisfy the predicate passed as a parameter while calling the function
std::optional<DataContainer> ReturnMatchingVehicles(const DataContainer& , const Predicate1 fn);



// A function to check if all vehicles have price above 90000.0f or not
bool AreAllVehiclePriceAbove90k(const DataContainer& );


//A function to find the average of CalculateRegistrationCost function value
float AverageRegistrationCost(const DataContainer&);


//A function to return a vector container of last N items from the data container where N is passed as a parameter to the function
std::optional<DataContainer> LastNvehicles(const DataContainer& vehicles, unsigned int N);



//function for applying hash on input value for unordered_set
std::size_t hash_logic(const VehicleSptr& v){
    return std::hash<MultimediaType>() (v->getvehicleMultimediaType());
}


//we are creating a new variable "comparision_fn"
extern std::function<bool(const VehicleSptr& v1, const VehicleSptr& v2)> comparision_fn;

using UniqueValues = std::unordered_set<VehicleSptr,std::function<std::size_t(const VehicleSptr& v)>, decltype(comparision_fn)>;

std::optional<UniqueValues> FindUniqueVehicles (const DataContainer& vehicles);
#endif // FUNCTIONALITIES_H
