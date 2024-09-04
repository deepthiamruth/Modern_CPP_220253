#include "Functionalities.h"

#include <future>

int main()
{

    // Declare the container
    Container data{};

    // Call the functions
    CreateObjects(data);

    // The Minhorsepower function can throw empty data exception
    try
    {
        // using the async threads and store the result in future variable
        std::future<std::string> result1 = std::async(&MinHorsePower, std::ref(data));
        std::string res1 = result1.get();
        std::cout << "Engine id which has min horsepower : " << res1 << "\n";
    }
    // only failure case is when data is empty
    catch (EmptyDataException &ex)
    {
        std::cout << ex.what() << "\n";
    }

    // predicate to return the engine with toruque > 100
    auto fn = [](const std::shared_ptr<Engine> &e)
    { return e->engineTorque() > 100.0f; };

    // FindmatchingEngine can throw empty data or no instance exceptions
    try
    {
        // using the async threads and store the result in future variable
        std::future<Container> result = std::async(&FindMatchinEngines, std::ref(data), fn);
        Container res1 = result.get();
        // iterate over the result container and print the objects
        for (const std::shared_ptr<Engine> &e : res1)
        {
            std::cout << "Matching engines : " << *e << "\n";
        }
    }
    // case1: if data is empty
    catch (EmptyDataException &ex)
    {
        std::cout << ex.what() << "\n";
    }
    // case2 : if not instance is found
    catch (NoMatchingInstance &ex)
    {
        std::cout << ex.what() << "\n";
    }

    // FindTypeByid may throw empty data exception or  id not found exception
    try
    {
        std::future<EngineType> result2 = std::async(&FindTypeById, std::ref(data), "e1");
        EngineType res2 = result2.get();
        std::cout << "Engine type for the given id : " << (int)res2 << "\n";
    }
    // case1: container might be empty
    catch (EmptyDataException &ex)
    {
        std::cout << ex.what() << "\n";
    }
    // case2: no object has the given id
    catch (IdNotFoundException &ex)
    {
        std::cout << ex.what() << "\n";
    }
}