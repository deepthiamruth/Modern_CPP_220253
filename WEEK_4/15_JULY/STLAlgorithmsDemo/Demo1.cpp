#include <memory>
#include "../stack_demo/Employee.h" //employee.h is not in this folder, it is outside this folder
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

    //check if all of the employees have age greater than 25
    bool result1 = std::none_of // none employee age > 25
    (stackEmployees.begin(),
     stackEmployees.end(),
     [](const Employee& e) {return e.age()>25;}
    );
    
    bool result2 = std::any_of  // atleast 1 employee age > 25
    (rawPtrEmployees.begin(),
     rawPtrEmployees.end(),
     [](const Employee* e) {return e->age()>25;}
    );
    std::cout << "heap  : " <<  result2 << "\n";

    bool result3 = std::all_of // all 5 employees age > 25
    (smartPtrEmployees.begin(),
     smartPtrEmployees.end(),
     [](const EmployeePtr& e) {return e->age()>25;}
    );

    std::cout << "stack : " << std::boolalpha <<  result1 << "\n";
    std::cout << "smart ptr: " << result3 << "\n";

    for(Employee* e : rawPtrEmployees){
        delete(e);
    }

}
