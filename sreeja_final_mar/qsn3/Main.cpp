#include "Functionalities.h"
#include <future>

int main()
{
    // create a container variable
    Container data{};
    CreateObjects(data);

    std::future<std::optional<float>> result1 = std::async(&AverageRTOCharges, std::ref(data));
    std::optional<float> res1 = result1.get();
    if (res1.has_value())
    {
        std::cout << "Average charges : " << res1.value() << "\n";
    }

    std::future<std::optional<bool>> result2 = std::async(&AreAllVehiclesValid, std::ref(data));
    std::optional<bool> res2 = result2.get();
    if (res2.has_value())
    {
        std::cout << "All vehicles are valid :" << std::boolalpha << res2.value() << "\n";
    }

    std::future<std::optional<std::shared_ptr<Permit>>> result3 = std::async(&FindPermitById, std::ref(data), "p1");
    std::optional<std::shared_ptr<Permit>> res3 = result3.get();
    if (res3.has_value())
    {
        std::cout << "Permit : " << *res3.value() << "\n";
    }

    std::future<std::optional<std::array<unsigned int, 5>>> result4 = std::async(&ReturnVehicleAgeValues, std::ref(data));
    std::optional<std::array<unsigned int, 5>> res4 = result4.get();
    int i = 0;
    if (res4.has_value())
    {
        while (!res4.has_value())
        {
            std::cout << "Array : " << res4.value().at(i);
            i++;
        }
    }
}