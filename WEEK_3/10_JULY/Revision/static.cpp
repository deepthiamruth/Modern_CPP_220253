///static keyword!!!

/*
    1)static storage variable 
    2) stati data member
    3) static member function
*/
#include <iostream>

void Increment(){
    static int n1{1};
    std::cout << n1++ << "\n";
}
class EmployeeData{
    private:
        static long long m_company_number;
        std::string m_employee_name;
    public :
        EmployeeData(std::string name) : m_employee_name{name}{

        }

        static long long companyNumber() { return EmployeeData::m_company_number; }

};

long long EmployeeData:: m_company_number = 8716442; //initialize static member outside the class


int main(){
    Increment(); // created n1 in static data segment . initial 1 print 1
    Increment(); 

    EmployeeData e1 {"deepthi"};

    std::cout << EmployeeData::companyNumber() << "\n";
}