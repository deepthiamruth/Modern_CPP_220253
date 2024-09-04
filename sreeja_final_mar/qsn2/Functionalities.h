#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include "IdNotFoundException.h"
#include "EmptyDataException.h"
#include "NoMatchingInstance.h"


#include <memory>
#include <functional>
#include <algorithm>

using Container = std::vector<std::shared_ptr<Engine>>;
using Predicate = std::function<bool (const std::shared_ptr<Engine>&)>;

void CreateObjects(Container& data);

std::string MinHorsePower(Container& data);

EngineType FindTypeById(Container& data, std::string id);

Container FindMatchinEngines(Container& data, Predicate fn);

#endif // FUNCTIONALITIES_H
