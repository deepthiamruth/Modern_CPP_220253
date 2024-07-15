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
#include <list>
#include <thread>
#include <optional>
#include "Car.h"
#include "Bike.h"
#include <mutex>

using VrType = std::variant <Car* , Bike*>;
using DataContainer = std::list <VrType>;
using ThreadContainer = std:: list <std::thread>;

class Operations
{
private:
    static DataContainer m_data;
    static ThreadContainer m_threads;
    static std::mutex mt;
public:
    Operations() = delete;
    ~Operations()=default;
    Operations (const Operations & ) = delete;
    Operations(Operations&& ) = delete;
    Operations& operator = (const Operations &) = delete;
    Operations& operator = (Operations&&) = delete;

    //getter for data
    DataContainer getdata() const { return m_data; }

    //--------------------------------------------------------------------------------


    static void CreateCarsAndBikes();


    //Find avg cost : use visit fun to do this , Both Car and Bike have a m_price attribute. We can use their getter fun to calculate total
    static void FindAverageCost();
   

    //may or may not return variant 
    //return matching instnace : variant whose id matches with the id passed
    static std::optional <VrType> ReturnMatchingInstance(std::string id);  



    static void Deallocate();



    static void DisplayInsuranceAmount(); 



    //s1: id found , matches with a car, seat count returned 
    //s2: id found , matches with bike not car  ----> nullopt
    //s3: id not found ---> nullopt (print a msg before return)
    static std::optional <unsigned int> FindSeatCountForGivenId(std::string id);



    //Mapthreads:attach a thread to a functionality 
    static void MapThreads();



    //JoinThreads: Blocking main for respective functions executing in threads 

    static void JoinThreads();


   
};



#endif // Operations_H
