#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Sensor.h"
#include "algorithm"
#include <memory>
#include <numeric>

using Container = std::array<std::shared_ptr<Sensor> ,4>;

void CreateObjects(Container& data);

std::optional<std::size_t> CountMatchingSensor(Container& data, SensorType type);

bool AreAllPricesBelowThreshold(Container& data);

float InsuranceCost(Container& data);

float ApplyPlus(Sensor& s1,  Sensor& s2);


#endif // FUNCTIONALITIES_H
