#include <memory>
#include "Employee.h" //employee.h is not in this folder, it is outside this folder
#include<list>
#include <numeric>
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

    float total_salary = std::accumulate(
        stackEmployees.begin(),
        stackEmployees.end(),
        0.0f,
        [](float ans_upto_now, const Employee& e){
            return ans_upto_now + e.salary();
        }
    );

    std:: cout << "Total salary is :" << total_salary << "\n";
}