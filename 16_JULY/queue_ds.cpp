/*
    10 20 30 40
    I would like to access data continously ? I want to access previous and next element of a certain element in the fastest time


*/
#include "Employee.h"
#include<queue>
#include<memory>

using Employeeptr = std::shared_ptr<Employee>;
using DataContainer = std::queue<Employeeptr>;

void CreateEntriesForQueue(DataContainer & data){
    data.emplace(std::make_shared<Employee> (101, "deepthi", 8734.9f, 22, 1));
    data.emplace(std::make_shared<Employee> (102, "sreeja", 92754.9f, 23, 5));
    data.emplace(std::make_shared<Employee> (103, "harshth", 62534.9f, 24, 7));
}


int main(){
    DataContainer employees{};
    CreateEntriesForQueue(employees);

    std::cout<< *employees.front() << "\n";

    std::cout << employees.size() << "\n";

    //can only read or fetch the data at the end of the queue
    std::cout << *employees.back() << "\n";
}