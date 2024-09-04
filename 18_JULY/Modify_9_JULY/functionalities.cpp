#include "functionalities.h"

void CreateObjects(DataContainer& objects){
//     objects.emplace_back(new Engine("6701", EngineType :: HYBRID,54.6f, 76.7f, 87 ));
//     objects.emplace_back(new Engine("6702", EngineType::ICE, 76.5f, 73.f , 65 ));
//     objects.emplace_back(new Engine("6703", EngineType::ALTERNATE_FUEL, 76.5f, 76.f , 54 ));
//     objects.emplace_back(new Engine("6704", EngineType::HYBRID, 71.5f, 54.f , 365 ));
//     objects.emplace_back(new Engine("6705", EngineType::ICE, 98.5f, 23.f , 35 ));

    objects.emplace_back(std::make_shared<Engine>("6701", EngineType::ALTERNATE_FUEL, 8734.f, 6534.6f, 87));

    objects.emplace_back(std::make_shared<Engine>("6702", EngineType::HYBRID, 8734.f, 6534.6f, 106));

    objects.emplace_back(std::make_shared<Engine>("6703", EngineType::ICE, 2534.f, 6624.6f, 145));

    objects.emplace_back(std::make_shared<Engine>("6704",EngineType::ALTERNATE_FUEL, 88914.f, 65814.6f, 25));

    objects.emplace_back(std::make_shared<Engine>("6705", EngineType::HYBRID, 8734.f, 66734.6f, 675));
}


std::optional <DataContainer> ReturnMatchingInstance(const DataContainer objects,const Logic & fn){
    bool m_input_empty {false};


    if(objects.empty()){ //flag to check if input is empty
        std::cerr <<"Empty\n";
        m_input_empty = true;
    }
    DataContainer result{};
    //for each srd_ptr in objects-> if predicate fn is applocable on the pointer -> store in result
    for(const srd_ptr & ptr : objects){
        if(fn(ptr)){
            result.emplace_back(ptr);
        }
    }


    if(!m_input_empty && result.empty()){ //input is not empty && result is empty
        return std::nullopt;
    }

    else if(!m_input_empty && !result.empty ()){ //input is not empty and result is also not empty
        return result;
    }
    else{
        return std::nullopt;
    }
}




bool IsAtleastOneInstanceMatching(const DataContainer objects, const Logic & fn ){
   bool m_input_empty {false};
    if(objects.empty()){ //flag to check if input is empty
        std::cerr <<"Empty\n";
        m_input_empty = true;
    }
    for(const srd_ptr& ptr : objects){
        if(fn(ptr)){
            return true;
        }
    }
    return false;
}


float FindAverage(const DataContainer & objects){

    bool m_input_empty {false};
    if(objects.empty()){ //flag to check if input is empty
        std::cerr <<"Empty\n";
        m_input_empty = true;
        return 0.0f;
    }
    float total{0.0f};
    for(const srd_ptr&  d: objects){
        total+= d->getengineCc();
    }
    return total/objects.size();
}



