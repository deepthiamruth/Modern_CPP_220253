#include "functionalities.h"



int main(){
    DataContainer objects{};//empty initialization
    CreateObjects(objects);

    auto fn1 = [] (const srd_ptr& ptr ){return ptr->getengineType() == EngineType::HYBRID;};
    auto fn2 = [](const srd_ptr& ptr){return ptr-> getengineHorsepower() >100; };


    std::future <std::optional <DataContainer> >result1 = std::async(&ReturnMatchingInstance,std::ref(objects), fn1 );
    std::future <bool>result2 = std::async(&IsAtleastOneInstanceMatching,std::ref(objects), fn2 );
    std::future<float> result3 = std::async(&FindAverage, std::ref(objects));


    if(result1.get().has_value()){
        std:: cout << "Matching Instance Found:\n";

    }


    bool flag = result2.get();
    std::cout <<"Is atlast one instance matching condition" << std::boolalpha<<flag << "\n";


    float ans = result3.get();
    std::cout << "Average engine cc:" << ans << "\n";


    std::optional <DataContainer> results = result1.get();
    if(results.has_value()){    
        DataContainer pointers = results.value();
        std::cout << "All pointers with objects satisfying condition:" << "\n";

        for(const srd_ptr d : pointers){
            std::cout << *d << "\n";
        }
    }    
}