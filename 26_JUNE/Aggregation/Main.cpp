#include <iostream>
#include "Employee.h"
#include "functionalities.h"
int main() {
    Employee* employees[3];
    Project* projects[3];
    CreateObjects(employees, projects, 3);
    Deallocate(employees, projects, 3);
}