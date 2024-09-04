#include "Functionalities.h"
#include <future>

int main() {
    Container data {};

    CreateObjects(data);

    std::cout << AddNewCar(data) << "\n";

    std::future<std::optional<std::size_t>> result1 = std::async(&CountCarType, std::ref(data), CarType::SEDAN);
    std::optional<std::size_t> res1 = result1.get();
    if(res1.has_value()) {
        std::cout << "Count : " << res1.value() << "\n";
    }

    std::future<std::optional<std::stack<std::shared_ptr<Car>>>> result3 = std::async(&ReturnMatchingInstances, std::ref(data), [] (const std::shared_ptr<Car>& v) { return v->seatCount() > 2;  });
    std::optional<std::stack<std::shared_ptr<Car>>> res3 = result3.get();
    if(res3.has_value()) {
        std::cout << "Stack top value : " << *res3.value().top() << "\n";
    }

    std::vector<std::string> input {"c1", "c2" }; 
    std::future<std::vector<mapContainer>> result4 = std::async(&ReturnCarTypes, std::ref(data), std::ref(input));
    std::vector<mapContainer> res4 = result4.get();
    for(auto [k,v] : res4) {
        std::cout << "Car Types : " << *v << "\n";
    }

}