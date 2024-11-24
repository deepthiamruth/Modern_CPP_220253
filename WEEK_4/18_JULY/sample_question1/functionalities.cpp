#include "functionalities.h"

//A function to create 5 objects of Vehicle class on the heap. Each object must be managed by a shared_ptr. The objects must be stored in a vector container.
void CreateObjects(DataContainer& vehicles)
{
    vehicles.emplace_back(std::make_shared<Vehicle>(StandardType::BS4, FuelType::ALTERNATE_FUEL, EngineType::HYBRID, MultimediaType::ANALOG, 67384.9f));

    vehicles.emplace_back(std::make_shared<Vehicle> (StandardType::BS6, FuelType::ICE,EngineType::NA, MultimediaType::ANDROID_SMART, 8374.9f));

    vehicles.emplace_back(std::make_shared<Vehicle> (StandardType::BS6_2, FuelType::OTHER, EngineType::REGULAR, MultimediaType::APPLE_ANDROID_SMART, 834983.8f));

    vehicles.emplace_back(std::make_shared<Vehicle> (StandardType::OTHER, FuelType::ALTERNATE_FUEL, EngineType::HYBRID, MultimediaType::APPLE_SMART, 87364.9f));

    vehicles.emplace_back(std::make_shared<Vehicle> (StandardType::BS4,FuelType::ICE,EngineType::NA, MultimediaType::ANDROID_SMART, 78816.9f ));
}


//A function to return a priority queue of all smart pointers in the data container where max priority is given to Vehicle with highest m_vehicle_price
std::priority_queue<pointer, DataContainer, decltype(fn)> CreatePriorityQueue(const DataContainer& vehicles){

    std::priority_queue<pointer, DataContainer, decltype(fn)> pq{vehicles.begin(), vehicles.end(), fn};

    for(pointer v : vehicles){
        pq.push(v);
    }
    return pq;
}



//A function to return one vehicle of each m_vehicle_multimedia_type category from the data container. 
//Hint: If there are 5 objects with types ANALOG, ANDROID_SMART, APPLE_SMART, ANALOG and ANDROID_SMART, return the first 3 objects only (unique category objects)
//[Hint: Create an unordered_set]
pointer CreateUnordered_set(const DataContainer& vehicles){
    
}


// A function to find the count of Vehicle objects whose m_vehicle_engine_type matches the m_vehicle_engine_type value given by the user.
std::optional <unsigned int> count_vehicles(DataContainer& vehicles, EngineType enginetype){
    if(vehicles.empty()){
        std::cerr << "Empty Container\n";
    }
    std::optional<unsigned int> result = {std::nullopt};
    result = std::count_if(
        vehicles.begin(),
        vehicles.end(),
        [enginetype] (const Vehicle& v){return v.getvehicleEngineType() == enginetype;}
    );
    return result;
}

// A function to check if all vehicles have price above 90000.0f or not
// [Hint: all_of]
std::optional<bool> CheckPrice(DataContainer& vehicles){
    std::optional <bool> result = std::all_of(
        vehicles.begin(),
        vehicles.end(),
        [](const pointer& v){return v->getvehiclePrice()>9000.0f;}
    );
    return result;
}

//A function to return a vector of instances which satisfy the predicate passed as a parameter while calling the function
std::optional<DataContainer> CopyVehicles(DataContainer& vehicles, Predicate1 fn){
    if(vehicles.empty()){
        std::cerr << "Empty Container\n";
    }
    DataContainer result {};

    std::copy_if(
        vehicles.begin(),
        vehicles.end(),
        std::inserter(result, result.begin()),
        [&](const DataContainer& v) {return fn(v);}
    );
    for(pointer v : result){
        return result;
    }
}



//A function to find the average of CalculateRegistrationCost function value
float accumulateData(const DataContainer& vehicles){
    float total_cost = std::accumulate(
        vehicles.begin(),
        vehicles.end(),
        0.0f,
        [&](float sum, const pointer& v){
            total_cost= sum+ v->CalculateRegistrationCost();
        }
    );
    return total_cost/vehicles.size();
}


//A function to return a vector container of last N items from the data container where N is passed as a parameter to the function
DataContainer copyNvehicles(DataContainer& vehicles, unsigned int n){
    DataContainer result{};
    std::copy_n(
        vehicles.begin(),
        n,
        std::inserter(result, result.begin())
    );
    for(pointer & v : result){
        return result;
    } 
}

