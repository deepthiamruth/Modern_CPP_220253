#include "Functionalities.h"
#include <future>

int main() {
    //create a container variable
    Container data {};

    //Call the functions
    CreateObjects(data);

    DisplayMatchingInstance(data, ConnectType::ANDROID_AUTO);

    //FindSystemById function which returns an optional systemtype
    std::future<std::optional<SystemType>> result1 = std::async(&FindSystemTypeById, std::ref(data), "a1");
    std::optional<SystemType> res1 = result1.get();
    if(res1.has_value()) {
        std::cout << "The system type for given id : " << (int) res1.value() << "\n";
    }

    //CopyLastN which return a container
    std::future<Container> result2 = std::async(&CopyLastNObjects, std::ref(data), 2);
    Container res2 = result2.get();
    for(auto& v : res2) {
        std::visit([] (auto&& val) { std::cout << *val << "\n"; } , v);
    }
    
}