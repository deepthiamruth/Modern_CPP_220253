/*
        Employee
            - int, string name, string designation, categorical dept, float salary
*/
#include <iostream>
#include "Department.h"
class Employee
{
private:
   unsigned int m_id {0};
   std:: string m_name {""};
   std:: string m_designation {"executive"};
   Department m_dept {Department ::HR};
   float m_salary {0.0f};
public:
    Employee() =default; // enable default const
    ~Employee() = default; //destructor is enabled
    Employee(const Employee& other) =  delete; //disable copy
    Employee& operator = (const Employee& other) = delete;
    Employee (Employee&& other) = delete; // move constructor
    Employee& operator= (Employee&& other) = delete;


    // Member list initialization
    Employee(unsigned int id, std:: string name, std:: string des, Department dept, float salary): m_id{id}, m_name{name}, m_salary{salary}, m_designation{des}, m_dept{dept}
    {

    }
};

int main(){
    //Employee * e1 = new Employee();
    Employee* ptr; // declaration of a pointer ptr of type employee
    //Employee * ptr =NULL;
    Employee * ptr = nullptr; //Replace NULL with nullptr

    ptr = new Employee();//default construction
    ptr = new Employee(101, "Deepthi" , "Trainer", Department :: IT, 900.0f); // parameterized construction;

    // Uniform initialization
    int n1(10);
    int * ptr{nullptr};
    int arr[2] {1,2};
    Employee e1{};
    Employee e2{102, "Rohan", "Admin", Department::HR, 8000.0f};

}