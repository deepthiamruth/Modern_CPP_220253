#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Employee.h"
void CreateObjects(Employee ** employees, Project ** projects, unsigned int size);

void Deallocate (Employee** employees, Project ** projects, unsigned int size);
#endif // FUNCTIONALITIES_H
