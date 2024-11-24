#include "Functionalities.h"

int main(){
    std:: vector <Engine* > engines;
    createobjects(engines,3);
    std::cout<<averagehorsepower(engines,3)<<"\n";
    try{
    std::cout<<findtorquebyid(engines,3,1)<<"\n";
    }catch(IDNotFoundException& ex){
        std::cerr<<ex.what()<<"\n";
    }
    std::cout<<FindHorsePowerForMinTorqueEngine(engines,3)<<"\n";
}