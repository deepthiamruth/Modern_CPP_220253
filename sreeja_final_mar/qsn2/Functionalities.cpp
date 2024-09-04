#include "Functionalities.h"

/*
    Function to create shared pointer of Engine objects and store it in vector container
*/

void CreateObjects(Container &data)
{

    data.emplace_back(std::make_shared<Engine>("e1", 120.0f, 23.9f, EngineType::REGULAR, 12.9f));
    data.emplace_back(std::make_shared<Engine>("e2", 130.0f, 103.9f, EngineType::TURBO, 22.9f));
    data.emplace_back(std::make_shared<Engine>("e3", 140.0f, 43.9f, EngineType::REGULAR, 32.9f));
    data.emplace_back(std::make_shared<Engine>("e4", 150.0f, 53.9f, EngineType::TURBO, 42.9f));
}

/*
    Function to find engine id with min horse power
    Returns the std::string id
*/

std::string MinHorsePower(Container &data)
{

    // Decalre an empty string result variable
    std::string result{""};

    int min{0};

    // check if data is empty
    if (data.empty())
    {
        // if so throw an exception
        throw EmptyDataException("Data is empty\n");
    }
    else
    {
        // Find the min elt with condition (min horsepower)
        auto min = std::min_element(data.begin(), data.end(), [&](const std::shared_ptr<Engine> &e1, const std::shared_ptr<Engine> &e2)
                                    { return e1.get()->engineHp() < e2.get()->engineHp(); });

        // store the min value in result
        result = min.base()->get()->engineId();
    }

    return result;
}

/*
    Function to find the engine type for the given engine id
    Returns the EngineType
*/

EngineType FindTypeById(Container &data, std::string id)
{
    // Declare an EngineType variable and intialize to REGULAR Type
    EngineType result{EngineType::REGULAR};

    // flag variable to check if id is found
    bool id_found{false};


    // if the conatiner is empty throw an exception
    if (data.empty())
    {
        throw EmptyDataException("Data is empty\n");
    }

    else
    {
        auto itr = std::find_if(data.begin(), data.end(), [&] (const std::shared_ptr<Engine>& e) { return e->engineId() == id; });
        result = itr->get()->engineType();
         // if id is not found i.e itr reaches the end throw the exception
        if(itr == data.end()) {
            throw IdNotFoundException("Id is invalid\n");
        }
    }
   
    return result;
}

/*
    Function to find the matching engines
    Returns a conatiner with objects matching the given predicate
*/

Container FindMatchinEngines(Container &data, Predicate fn)
{
    // an empty result container
    Container result{};

    // a flag variable to check if object is found
    bool object_found{false};

    // if data is empty throw the exception
    if (data.empty())
    {
        throw EmptyDataException("Empty container\n");
    }

    else
    {
        std::copy_if(data.begin(), data.end(), std::inserter(result, result.begin()) , fn);
    }

    if(result.empty()) {
        throw NoMatchingInstance("No object satisfy the given predicate\n");
    }

    return result;
}
