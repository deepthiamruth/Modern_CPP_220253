#ifndef Operations_H
#define Operations_H

/*
1)create Car and Operationss
2)find averagecost of vehicles  : print the avg price of all vehicles in our database
3)return matching instance : return the first vehicle whose id matches with the id parameter received
4) deallocate : release heap allocation if any
5) displayinsuranceamount : show output of insuranceamount function for each instance
6) Find seat count for given id : fetches vehicle based on ID and returns corresponding seat_count
*/

#include <iostream>
#include <variant>
#include <unordered_map>
#include <list>
#include <thread>
#include <optional>
#include "Car.h"
#include "Bike.h"
#include <mutex>
#include<memory>

using VrType = std::variant <std::shared_ptr <Car> , std::shared_ptr <Bike>>;
using DataContainer = std::unordered_map<std::string, VrType>;
using ThreadContainer = std:: list <std::thread>;

void CreateCarsAndBikes(DataContainer&);


    //Find avg cost : use visit fun to do this , Both Car and Bike have a m_price attribute. We can use their getter fun to calculate total
void FindAverageCost(DataContainer& );
   

    //may or may not return variant 
    //return matching instnace : variant whose id matches with the id passed
std::optional <VrType> ReturnMatchingInstance(DataContainer& , std::string id);  


void DisplayInsuranceAmount(DataContainer& data); 

    //s1: id found , matches with a car, seat count returned 
    //s2: id found , matches with bike not car  ----> nullopt
    //s3: id not found ---> nullopt (print a msg before return)
std::optional <unsigned int> FindSeatCountForGivenId(DataContainer& , std::string id);



    //Mapthreads:attach a thread to a functionality 
void MapThreads(DataContainer& data, ThreadContainer& threads);



    //JoinThreads: Blocking main for respective functions executing in threads 

void JoinThreads(ThreadContainer& threads);




#endif // Operations_H
