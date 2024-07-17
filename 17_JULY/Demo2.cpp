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

//===========================================================================

  //Count of objects which satisfy a given condition
    std::cout << std::count_if(
        stackEmployees.begin(), 
        stackEmployees.end(), 
        [] (const Employee& e) { return e.age()>20; }) << "\n";
 
    std::cout << std::count_if(
        rawPtrEmployees.begin(),
         rawPtrEmployees.end(), 
         [] (const Employee* e) { return e->age()>20; }) << "\n";
 
//==================================================================================
   std::vector<Employee> result{};

    //solution no.1
    //Example1 - copy_if
    std::copy_if( //copy should be enabled
    stackEmployees.begin(), 
    stackEmployees.end(),
    std::inserter(result, result.begin()), // create a inserter , if destination does not have memory allocate memory 
    [](const Employee& e){return e.age() >20;}
   );
   for(Employee& e :result){
    std::cout << "copy if age >20 " << e << "\n";
   }
  



    //Example2 ---> copy n no of items
    std::vector <Employee> result2{};
    std::copy_n(
    stackEmployees.begin(),
    2,
    std::inserter(result2, result2.begin())
   );
   for(Employee& e :result2){
    std::cout << "copy_n , copy first 2 employees " << e << "\n";
   }
    


    //Example 3 --->copy everything
    std::vector < Employee*> result3{rawPtrEmployees.size()};
    std::copy(
        rawPtrEmployees.begin(),
        rawPtrEmployees.end(),
        result3.begin()
    );

    for(Employee* e :result3){
    std::cout << "copy everything " << *e << "\n";
   }
}



