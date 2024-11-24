#include "Employee.h"

//before entering the constructor class you need to initialize project
Employee::Employee(int id, std::string name, ProjectRef pr): _project(pr)
{
    this-> _id =id;
    this->_name =name;
}
Employee:: ~Employee(){
    std:: cout <<"Destroyed";
}

