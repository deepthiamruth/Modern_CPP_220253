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


        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
            os << "_id: " << rhs._id
               << " _name: " << rhs._name
               << " _project: " << rhs._project.get();
            return os;
        }

        int getid() const { return _id; }


        std::string getname() const { return _name; }


    
        ProjectRef getproject() const { return _project; }
};



/*
    Replace c style arrays with vectors
    Add a feature to filter employees based on filter predicates (functional style)
    Add a feature to calculate bonus for each employee using a formula given by the user (functional style) [Mapping lambda]
    example : each employee gets 2000 rs bonus
    example 2: each employee gets bonus = 100000 / project_team size

*/


    

  

     
#endif 