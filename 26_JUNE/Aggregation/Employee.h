#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include "Project.h"
#include <functional>

using ProjectRef = std:: reference_wrapper<Project>;

class Employee{
    private:
        int _id;
        std::string _name;
        ProjectRef _project;
    public:
        Employee(int id, std::string name, ProjectRef ptr);
        ~Employee();
};

#endif 

/*
    Replace c style arrays with vectors
    Add a feature to filter employees based on filter predicates (functional style)
    Add a feature to calculate bonus for each employee using a formula given by the user (functional style) [Mapping lambda]
    example : each employee gets 2000 rs bonus
    example 2: each employee gets bonus = 100000 / project_team size

*/
