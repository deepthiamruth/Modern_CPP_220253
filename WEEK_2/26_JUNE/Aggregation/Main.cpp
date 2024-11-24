#include <iostream>
#include "functionalities.h"
int main() {
    EmployeeContainer employees{};
    ProjectContainer projects{};
    CreateObjects (employees, projects);

    //filter all employees whose project team count is above 10
    auto fn = [](const Employee* emp){
        return emp-> getproject().get().getteamsize() >10;
        //return emp->getname() == "Harshith";
    };
    FilterEmployees(fn, employees);
   // FilterEmployees(&Greater, employees);
}
