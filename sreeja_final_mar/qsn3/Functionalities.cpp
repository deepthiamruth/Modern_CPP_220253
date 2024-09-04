#include "Functionalities.h"

/*
    Function to create objects and store it in an array
*/
void CreateObjects(Container &data)
{

    data[0] = std::make_shared<CommercialVehicle>("cv1", 1200.0f, 4, std::make_shared<Permit>("p1", 120.0f, ChassisType::LEASE));
    data[1] = std::make_shared<CommercialVehicle>("cv2", 1300.0f, 2, std::make_shared<Permit>("p2", 220.0f, ChassisType::OWNED));
    data[2] = std::make_shared<CommercialVehicle>("cv3", 1400.0f, 6, std::make_shared<Permit>("p3", 420.0f, ChassisType::OWNED));
    data[3] = std::make_shared<CommercialVehicle>("cv4", 1500.0f, 1, std::make_shared<Permit>("p4", 920.0f, ChassisType::LEASE));
}

/*
    Function to calculate the average
*/
std::optional<float> AverageRTOCharges(Container &data)
{
    std::optional<float> result{std::nullopt};

    float sum{0.0f};

    // if container is empty
    if (data.empty())
    {
        std::cout << "Empty container\n";
        return result;
    }

    else
    {
        // accumulate algorithm to calculate the sum
        sum = std::accumulate(
            data.begin(),
            data.end(),
            0.0f,
            [&](float ans = 0.0f, const std::shared_ptr<CommercialVehicle> &cv)
            { return ans + cv->CalculateRTOCharges(); });

        result = sum / data.size();
    }

    return result;
}

/*
    Function to check if all vehicles are valid
*/
std::optional<bool> AreAllVehiclesValid(Container &data)
{
    std::optional<bool> result{std::nullopt};

    // a flag variable
    bool is_true{false};

    if (data.empty())
    {
        std::cout << "Empty container\n";
        return result;
    }
    else
    {
        // using the all_of algorithm with given 2 conditions
        is_true = std::all_of(data.begin(), data.end(), [](const std::shared_ptr<CommercialVehicle> &cv)
                              { return ((cv->vehicleAge() > 8) && (cv->permit()->chassisType() == ChassisType::OWNED)); });

        result = is_true;
    }

    return result;
}

/*
    Function to return the array with the vehicleAge values of all objects
*/
std::optional<std::array<unsigned int, 5>> ReturnVehicleAgeValues(Container &data)
{
    std::optional<std::array<unsigned int, 5>> result{std::nullopt};

    // Creating an array variable to store the result
    std::array<unsigned int, 5> arr{};

    if (data.empty())
    {
        std::cout << "Empty container\n";
        return result;
    }
    else
    {
        // std::copy_if(data.begin(), data.end(), std::inserter(arr, arr.begin()), [] (const std::shared_ptr<CommercialVehicle>& cv) { return cv->vehicleAge(); });
        // result = arr;
        for (int i = 0; i < data.size(); i++)
        {
            arr[i] = data.at(i).get()->vehicleAge();
        }
        result = arr;
    }
    return result;
}

/*
    Function to find the permit by the id passed as input parameter
*/

std::optional<std::shared_ptr<Permit>> FindPermitById(Container &data, std::string permit_id)
{
    // create a result variable
    std::optional<std::shared_ptr<Permit>> result{std::nullopt};
    std::shared_ptr<Permit> res{};
    if (data.empty())
    {
        std::cout << "No data\n";
        return result;
    }

    else
    {
        // using the find_if algorithm to find the vehicle with given id
        auto itr = std::find_if(data.begin(), data.end(), [&](const std::shared_ptr<CommercialVehicle> &cv)
                                { return cv->permit()->permitRegNumber() == permit_id; });

        // storing the permit in res variable
        res = itr->get()->permit();

        // the itr reaches the end, if the id is not found
        if (itr == data.end())
        {
            std::cout << " No such id found\n";
        }
        result = res;
    }
    return result;
}
