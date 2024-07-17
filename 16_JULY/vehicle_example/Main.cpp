#include "Operations.h"

int main(){
    //step 1: make objects
    DataContainer data {};
    ThreadContainer threads {};
    CreateCarsAndBikes(data);

    //Execute parallel functions
    MapThreads(data, threads);
    JoinThreads(threads);

    //step 3: serial functions

    std:: optional <unsigned int > result1 = FindSeatCountForGivenId (data, "c6701");
    if(result1.has_value()){
        std:: cout << "Seat count for id is: " << result1.value() << "\n";
    }

    std::optional <VrType> result2 =  ReturnMatchingInstance(data, "b6601");

    if(result2.has_value()){
        std:: cout << "Matching instance found :" << "\n";
        std:: visit ([] (auto&& val){std:: cout << *val<<"\n"; }, result2.value());
    }


}