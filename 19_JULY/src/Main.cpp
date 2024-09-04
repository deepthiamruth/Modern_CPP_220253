#include "functionalities.h"

int main(){
    DataContainer vehicles;
    CreateObjects(vehicles);
    std::future <PriorityQ> result = std::async(&PrioritizeVehicles, std::ref(vehicles));
    PriorityQ result1 = result.get();
    std::cout << result1.top() << "\n";
}