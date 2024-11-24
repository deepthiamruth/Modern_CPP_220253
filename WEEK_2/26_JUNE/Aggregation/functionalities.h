#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Employee.h"

#include <list>
//#include<vector>

using EmployeeContainer = std:: list <Employee*>;
using ProjectContainer=std:: list<Project*>;
using Predicate = std:: function <bool (const Employee*)>;

void CreateObjects(EmployeeContainer& employees, ProjectContainer & projects);

void Deallocate (EmployeeContainer employees, ProjectContainer projects);

// Add a feature to filter employees based on filter predicates(functional style) [FILTER LAMBDA]
//bool Greater(const Employee* employees);
void FilterEmployees( Predicate fn ,const EmployeeContainer& employees);

#endif // FUNCTIONALITIES_H
