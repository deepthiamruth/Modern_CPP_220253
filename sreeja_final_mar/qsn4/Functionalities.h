#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Analog.h"
#include "Digital.h"

#include <variant>
#include <memory>
#include <vector>
#include <optional>
#include <algorithm>

using Container = std::vector<std::variant<std::shared_ptr<Analog>, std::shared_ptr<Digital>>>;

void CreateObjects(Container& data);

void DisplayMatchingInstance(Container& data, ConnectType connect_type);

std::optional<SystemType> FindSystemTypeById(Container& data, std::string id);

// std::optional<Container> CopyLastNObjects(Container& data, unsigned int n);

Container CopyLastNObjects(Container& data, unsigned int n);

#endif // FUNCTIONALITIES_H
