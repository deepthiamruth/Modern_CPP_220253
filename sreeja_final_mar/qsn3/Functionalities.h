#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "CommercialVehicle.h"

#include <memory>
#include <optional>
#include <algorithm>
#include <numeric>

using Container = std::array<std::shared_ptr<CommercialVehicle>,4>;

void CreateObjects(Container& data);

std::optional<float> AverageRTOCharges(Container& data);

std::optional<bool> AreAllVehiclesValid(Container& data);

std::optional<std::array<unsigned int, 5>> ReturnVehicleAgeValues(Container& data);

std::optional<std::shared_ptr<Permit>> FindPermitById(Container& data, std::string permit_id);

#endif // FUNCTIONALITIES_H
