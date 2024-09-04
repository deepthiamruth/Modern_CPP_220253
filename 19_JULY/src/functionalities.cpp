#include "functionalities.h"
Comparator fn;

std::function<bool(const VehicleSptr& , const VehicleSptr& )> comparision_fn = [](const VehicleSptr& v1, const VehicleSptr&  v2){
    return v1->getvehicleMultimediaType() == v2->getvehicleMultimediaType();
};


// A function to create 5 objects of Vehicle class on the heap. Each object must be managed by a shared_ptr. The objects must be stored in a vector container.
void CreateObjects(DataContainer &vehicles)
{
    vehicles.emplace_back(std::make_shared<Vehicle>(StandardType::BS4, FuelType::ALTERNATE_FUEL, EngineType::HYBRID, MultimediaType::ANALOG, 67384.9f));

    vehicles.emplace_back(std::make_shared<Vehicle>(StandardType::BS6, FuelType::ICE, EngineType::NA, MultimediaType::ANDROID_SMART, 8374.9f));

    vehicles.emplace_back(std::make_shared<Vehicle>(StandardType::BS6_2, FuelType::OTHER, EngineType::REGULAR, MultimediaType::APPLE_ANDROID_SMART, 834983.8f));

    vehicles.emplace_back(std::make_shared<Vehicle>(StandardType::OTHER, FuelType::ALTERNATE_FUEL, EngineType::HYBRID, MultimediaType::APPLE_SMART, 87364.9f));

    vehicles.emplace_back(std::make_shared<Vehicle>(StandardType::BS4, FuelType::ICE, EngineType::NA, MultimediaType::ANDROID_SMART, 78816.9f));
}


//A function to return a priority queue of all smart VehicleSptrs in the data container where max priority is given to Vehicle with highest m_vehicle_price
PriorityQ PrioritizeVehicles(const DataContainer& vehicles){
    if(vehicles.empty()){
        std::cerr << "Empty Vehicles\n";
    }

    PriorityQ pq{vehicles.begin(),vehicles.end(),fn };
    return pq;
}

// A function to find the count of Vehicle objects whose m_vehicle_engine_type matches the m_vehicle_engine_type value given by the user
std::optional<std::size_t> CountMatchingEngineTypeVehicle(const DataContainer &vehicles, const EngineType engine_type)
{

    std::optional<std::size_t> result{std::nullopt};

    if (vehicles.empty())
    {
        std::cerr << "No data found in input\n";
    }
    else
    {
        result = std::count_if(
            vehicles.begin(),
            vehicles.end(),
            [&](const VehicleSptr &v)
            { return v->getvehicleEngineType() == engine_type; });
    }
    return result;
}


//A function to return a vector of instances which satisfy the predicate passed as a parameter while calling the function
std::optional<DataContainer> ReturnMatchingVehicles(const DataContainer &vehicles, const Predicate1 fn)
{
    std::optional<DataContainer> result{std::nullopt};

    if (vehicles.empty())
    {
        std::cerr << "No data found in input\n";
    }
    else{
        DataContainer values{};
        std::copy_if(
            vehicles.begin(),
            vehicles.end(),
            std::inserter(values,values.begin()),
            fn
        );
        if(!values.empty()){
            result= values;
        }
    }
    return result;
}


// A function to check if all vehicles have price above 90000.0f or not
bool AreAllVehiclePriceAbove90k(const DataContainer& vehicles){
    bool flag {false};

    if(vehicles.empty()){
        std::cerr << "No data found in input\n";
    }

    else{
        flag = std::all_of(
            vehicles.begin(),
            vehicles.end(),
            [](const VehicleSptr& v){return v->getvehiclePrice()> 90000.0f;}
        );
    }
    return flag;
}


//A function to return a vector container of last N items from the data container where N is passed as a parameter to the function
std::optional<DataContainer> LastNvehicles(const DataContainer& vehicles, unsigned int N){
    std::optional <DataContainer> result {std::nullopt};
    if(vehicles.empty()){
        std::cerr << "No data found\n";
    }
    if(N> vehicles.size()){
        std::cerr << "N is invalid as it is more than size\n";
    }
    else{
        DataContainer values{};
        std::copy_n(
            vehicles.rbegin(),
            N,
            std::inserter(values,values.begin())
        );
        result = values;
    }
    return result;
}

std::optional<UniqueValues> FindUniqueVehicles (const DataContainer& vehicles){
    std::optional<UniqueValues> result {std::nullopt};

    if(vehicles.empty()){
        std::cerr << "No data found\n";
    }
    else{
        UniqueValues values { vehicles.begin(), vehicles.end(),vehicles.size(),  hash_logic, comparision_fn};
        result = values;
    }
    return result;
}






