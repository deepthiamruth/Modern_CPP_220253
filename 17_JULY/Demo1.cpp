#include <memory>
#include "Employee.h" //employee.h is not in this folder, it is outside this folder
#include<list>
#include<algorithm>

using StackMemory = std::list<Employee>;
using RawpointerHeap = std:: list <Employee*>;
using EmployeePtr = std::shared_ptr <Employee>;
using SmartPointersHeap = std::list <EmployeePtr>;

void CreateObjects(StackMemory& stackEmployees){
    stackEmployees.emplace_back(101, "Deepthi", 89754.0f, 22, 1.0f);
    stackEmployees.emplace_back(102, "Adithi", 90764.0f, 20, 1.4f);
    stackEmployees.emplace_back(103, "Dhatu", 56454.0f, 23, 5.0f);
}

void CreateObjects(RawpointerHeap& rawPtrEmployees){
    rawPtrEmployees.emplace_back(new Employee(101, "Deepthi", 89754.0f, 22, 1.0f));
    rawPtrEmployees.emplace_back(new Employee(102, "Adithi", 90764.0f, 25, 1.4f));
    rawPtrEmployees.emplace_back(new Employee(103, "Dhatu", 56454.0f, 32, 5.0f));
}

void CreateObjects(SmartPointersHeap& smartPtrEmployees){
    smartPtrEmployees.emplace_back( std::make_shared<Employee>(101, "Deepthi", 89754.0f, 22, 1.0f));
    smartPtrEmployees.emplace_back( std::make_shared<Employee>(102, "Adithi", 90764.0f, 25, 1.4f));
    smartPtrEmployees.emplace_back( std::make_shared<Employee>(103, "Dhatu", 56454.0f, 32, 5.0f));
}

int main(){
    StackMemory stackEmployees{};
    RawpointerHeap rawPtrEmployees{};
    SmartPointersHeap smartPtrEmployees{};

    CreateObjects(stackEmployees);
    CreateObjects(rawPtrEmployees);
    CreateObjects(smartPtrEmployees);

    ///////////////////////////////////////////
    //if there are multiple maximums , then consider the first one found
    //11, 9, 7, 10, 18, 7

    auto result1= std::max_element(
    stackEmployees.begin(),
    stackEmployees.end(),
    [](const Employee& e1, const Employee& e2){
        return e1.experienceYears() < e2.experienceYears(); 
    });

    std::cout << "The name of employee with maximum experience is :" << (*result1).name() <<"\n";

    auto result2= std::max_element(
    rawPtrEmployees.begin(),
    rawPtrEmployees.end(),
    [](const Employee* e1, const Employee* e2){
        return e1->experienceYears() < e2->experienceYears();
    });

    std::cout << "The name of employee with maximum experience is :" << (*result2)->name() <<"\n";

}



