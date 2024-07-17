//Move and copy should be enabled

#include "Employee.h"
#include<queue>

/*
    1) what kind of data goes into priority queue
    2) What is the backend of the queue to store the data? //vector is default
    3) What is the comparision logic(also called "Comparator")
*/

int main(){
    std::vector<Employee> employees;
    employees.emplace_back(101, "Deepthi", 89754.0f, 22, 1.0f);
    employees.emplace_back(102, "Adithi", 90764.0f, 20, 1.4f);
    employees.emplace_back(103, "Dhatu", 56454.0f, 23, 5.0f);


    auto fn = [] (const Employee& e1, const Employee& e2 ){return e1.experienceYears()> e2.experienceYears();};
    std::priority_queue <Employee,std :: vector < Employee> , decltype(fn) > pq{employees.begin(), employees.end(),fn };
}

/*
    [Cpp is a stringly & statically typed language]
    1) In cpp everything must have a type , including functions!

    2) A lambda in c+= is an object that behaves like a function.

    3) Lambda is always implemented by the compiler by creating a class during compilation. Name of this class is unknown to us!

    4) So, my req is : compiler should create fn lambda. Its type will be known to the compiler

    The declared type of fn is what I obtain to obtain from the compiler
*/