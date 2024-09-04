#include "Functionalities.h"

comparator comparator_fn = [] (const std::shared_ptr<Car>& c1, const std::shared_ptr<Car>& c2) { return c1->chassisLength() > c2->chassisLength(); };

void CreateObjects(Container& data) {
    data.emplace(std::piecewise_construct, std::forward_as_tuple("c1"), std::forward_as_tuple(std::make_shared<Car>("c1", 1, 123.9f, CarType::OTHER, 4)));
    data.emplace(std::piecewise_construct, std::forward_as_tuple("c2"), std::forward_as_tuple(std::make_shared<Car>("c2", 2, 223.9f, CarType::SEDAN, 2)));
    data.emplace(std::piecewise_construct, std::forward_as_tuple("c3"), std::forward_as_tuple(std::make_shared<Car>("c3", 3, 113.9f, CarType::SUV, 7)));
    data.emplace(std::piecewise_construct, std::forward_as_tuple("c4"), std::forward_as_tuple(std::make_shared<Car>("c4", 4, 127.9f, CarType::OTHER, 3)));

}

bool AddNewCar(Container &data)
{
    std::string id;
    unsigned int category;
    float length;
    CarType cartype;
    int ctype;
    float seatcount;

    std::cin >> id;
    std::cin >> category;
    std::cin >> length;
    std::cin >> ctype;
    std::cin >> seatcount;

    data.emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(std::make_shared<Car>(id, category, length, (CarType)ctype, seatcount)));
    return true;

}

std::optional<std::size_t> CountCarType(Container &data, CarType carType)
{
    std::optional<std::size_t> result {std::nullopt};

    if(data.empty()) {
        std::cout << "Empty data\n";
        return result;
    }
    else {
        int count = std::count_if(data.begin(), data.end(), [&] (const std::pair<std::string, std::shared_ptr<Car>>& v) { return v.second->carType() == carType; });
        result = count;
    }
    return result;
}

// pq PriorityQueue(Container &data, comparator fn)
// {
//     if(data.empty()) {
//         std::cout << "Empty container\n";
//     }
//     pq result {data.begin(), data.end(), comparator_fn};
//     return result;
// }

std::optional<std::stack<std::shared_ptr<Car>>> ReturnMatchingInstances(Container &data, Predicate fn)
{
    std::optional<std::stack<std::shared_ptr<Car>>> result{std::nullopt};

    std::stack<std::shared_ptr<Car>> res {};

    if(data.empty()) {
        std::cout << "Empty container\n";
        return result;
    }

    else {
        for(std::pair<std::string, std::shared_ptr<Car>> car : data) {
            if(fn(car.second)) {
                res.push(car.second);
            }
        }
        result = res;
    }
    return result;
}

std::vector<mapContainer> ReturnCarTypes(Container &data, std::vector<std::string>)
{
    return std::vector<mapContainer>();
}

std::vector<mapContainer> ReturnCarTypes(Container &data, std::vector<std::string>& vec)
{
    int len = vec.size();
    int i=0;
    std::vector<mapContainer> res {};
    mapContainer result {};
    if(data.empty()) {
        std::cout << "Empty container\n";
    }
    else {
        for(std::pair<std::string, std::shared_ptr<Car>> c : data) {
                if(c.first == vec[i]) {
                    result.emplace(vec[i], c.second->carType());
                }
        }
        res.emplace_back(result);
    }
    return res;
}
