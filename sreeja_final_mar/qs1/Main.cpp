#include "Functionalities.h"

int main() {
    //Data container 
    Container data {};

    //Calling the appropriate functions
    CreateObjects(data); std::cout << "After adding the readings : " << ApplyPlus(*data[0], *data[1]) << "\n";

    //Count of matching sensors
    std::optional<std::size_t> result1 = CountMatchingSensor(data, SensorType::EMPLACED);
    //check if result1 has value or not
    if(result1.has_value()) { 
        std::cout << "Count of matching sensors : " << result1.value() << "\n";
    } 

    //if all the objects have price below threshold
    bool result2 = AreAllPricesBelowThreshold(data);
    std::cout << "All are below threshold " << std::boolalpha << result2<< "\n";
    

    //Total insurance cost
    std::cout << "Total insurance cost : " << InsuranceCost(data) << "\n";
    // std::cout << "After adding : " << data[0].get()->operator+(*data[1]) << "\n";

    std::cout << "After adding the readings : " << ApplyPlus(*data[0], *data[1]) << "\n";
}