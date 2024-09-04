#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Car.h"

#include <unordered_map>
#include <memory>
#include <optional>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <vector>

using Container = std::unordered_map<std::string, std::shared_ptr<Car>>;
using Predicate = std::function<bool (const std::shared_ptr<Car>&)>;

void CreateObjects(Container& data);

bool AddNewCar(Container& data);

std::optional<std::size_t> CountCarType(Container& data, CarType);

using comparator = std::function<bool (const std::shared_ptr<Car>& , const std::shared_ptr<Car>& )>;

extern comparator comparator_fn;

// auto comparator_fn = [] (const std::shared_ptr<Car>& c1, const std::shared_ptr<Car>& c2) { return c1->chassisLength() > c2->chassisLength(); };

using pq = std::priority_queue<std::pair<std::string, std::shared_ptr<Car>>, Container, decltype(comparator_fn)>;

pq PriorityQueue(Container& data, comparator fn);

std::optional<std::stack<std::shared_ptr<Car>>> ReturnMatchingInstances(Container& data, Predicate fn);

using mapContainer = std::unordered_map<std::string, CarType>;
// std::vector<mapContainer>;
std::vector<mapContainer> ReturnCarTypes(Container& data, std::vector<std::string>& vec);

#endif // FUNCTIONALITIES_H
