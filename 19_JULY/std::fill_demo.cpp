/*
    If I have a memory locations already allocated upto a certain size, I can "fill" all locations with "some" value using this algorithm

    for e.g. std::vector <int> data {5}; //size 5 vector
    std::fill (data.begin(), data.end(), 11);

    result : data{11,11,11,11,11};

    for e.g. std::array<int,5> arr{}; //array of 5 locations

    std::fill(arr.begin(), arr.end(), 11);
    result: arr : {11,11,11,11,11}
*/
#include<memory>
#include "Employee.h"
#include<list>
#include <algorithm>
 
using StackMemoryEmployee= std::list<Employee>;
using RawPointerHeapEmployees= std::list<Employee*>;
using EmployeePtr = std::shared_ptr<Employee>;
using SmartPointerHeapEmployees= std::list<EmployeePtr>;
 
 
int main()
{
    StackMemoryEmployee stackemployees{};
    RawPointerHeapEmployees rawpointerheapemployees{};
    SmartPointerHeapEmployees smartpointerheapemployees{};
 
    std::fill(
        stackemployees.begin(), stackemployees.end(),new Employee{}
    );
 
    std::fill(
        rawpointerheapemployees.begin(),rawpointerheapemployees.end(), new Employee{}
    );
 
    std::fill(
        smartpointerheapemployees.begin(),smartpointerheapemployees.end(), std::make_shared<Employee>()
    );
    
}
    