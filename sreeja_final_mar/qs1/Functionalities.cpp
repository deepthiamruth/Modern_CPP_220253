#include "Functionalities.h"

/*
    Create the Sensor objects and store it in an array
*/

void CreateObjects(Container &data)
{
    data[0] = std::make_shared<Sensor>("s1", 12.0f, SensorType::EMPLACED);
    data[1] = std::make_shared<Sensor>("s2", 22.0f, SensorType::FUSED);
    data[2] = std::make_shared<Sensor>("s3", 32.0f, SensorType::INDEPENDENT);
    data[3] = std::make_shared<Sensor>("s4", 42.0f, SensorType::EMPLACED);
}

/*
    Function to count the matching sensors
    Returns the optional size_t

*/
std::optional<std::size_t> CountMatchingSensor(Container &data, SensorType type)
{
    // initialize an optional size_t varaiable with nullopt
    std::optional<std::size_t> result{std::nullopt};

    // count_if method to check if it matches the given type
    std::size_t count = std::count_if(data.begin(), data.end(), [&](const std::shared_ptr<Sensor> &s)
                                      { return s->sensorType() == type; });

    // store count in result
    result = count;
    return result;
}

/*
    Function to check if all objects have price below threshold
    Returns an optional
*/
bool AreAllPricesBelowThreshold(Container &data)
{
    // a flag variable set to false
    bool result{false};

    // use allof algorithm to check if all objects satisfy the condition
    result = std::all_of(data.begin(), data.end(), [](const std::shared_ptr<Sensor> &s)
                         { return s->reading() < 90.0f; });
    return result;
}

/*
    Display the total insurance
    Returns a float value
*/
float InsuranceCost(Container &data)
{
    // initialize sum = 0
    float sum{0.0f};

    // Use accumulate to find the sum of insurance for all objects
    sum = std::accumulate(data.begin(), data.end(), 0.0f, [&](float ans = 0.0f, std::shared_ptr<Sensor> & s)
                          { return sum = ans + s->CalculateErrorDeviation(); });
    return sum;
}

/*
    To add the readings of the object
*/
float ApplyPlus(Sensor &s1, Sensor &s2)
{
    // use the overloaded + operator
    float sum = s1 + s2;
    return sum;
}
