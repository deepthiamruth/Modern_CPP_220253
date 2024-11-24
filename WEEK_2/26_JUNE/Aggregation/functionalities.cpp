#include "functionalities.h"

void CreateObjects(EmployeeContainer& employees, ProjectContainer &projects){

    projects.emplace_back (new Project("c.111", 10, 10000.0f));
    projects.emplace_back (new Project("c.123", 20, 11000.0f));
    projects.emplace_back (new Project("c.276", 30, 13000.0f));

//////////////////////////////////////////////////////
    auto itr = projects.begin(); //itr is pointing to the beginning of the projects list

    employees.emplace_back ( new Employee (103, "Harshith", **itr++));
    employees.emplace_back ( new Employee (104, "ram",  **itr++));
    employees.emplace_back ( new Employee (105, "Riya",  **itr++));

    
}
void Deallocate(EmployeeContainer employees, ProjectContainer projects){
    for(Employee* emp : employees){
        delete emp;
    }
    for(Project* pr : projects){
        delete pr;
    }
}

// bool Greater(const Employee *employees)
// {
//     // auto fn = [](const Employee* emp){
//     //     return emp-> getproject().get().getteamsize() >10;

//         // for(Employee* emp: employees  )
//         // {
//             //auto fn = [](const Employee* emp){
//         //return 
//         if(employees->getproject().get().getteamsize() >1) {
//             std:: cout << *employees <<"\n";
//         }
//         return true;
//         //}
// }

auto fn = [](const Employee* emp){
        return emp-> getproject().get().getteamsize() >10;
};
void FilterEmployees(Predicate fn, const EmployeeContainer &employees)
{

    for(const Employee* emp : employees){
        if(fn(emp)){
           // std::cout << "Employee found\n";
            std:: cout <<* emp << "\n";
        }
    }
}

void DisplayProjectBudget(const EmployeeContainer &employees){
    for(const Employee* emp : employees){
        std:: cout << emp -> getproject() . get() . getbudget () << "\n";
   }
}