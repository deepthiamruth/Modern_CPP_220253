#include<stack>
#include<iostream>
#include "Employee.h"

int main(){
    std::stack<Employee> s{};

    s.emplace(101, "Deepthi" , 19000.0f, 22, 0.5f);
    s.emplace(102, "Harshith" , 890000.0f, 28, 1.5f);
    s.emplace(103, "Sreeja" , 20000.0f, 21, 0.5f);

    //Display top item and then pop 
    std::cout << "top " << s.top() << "\n";
    s.pop();

    //check size:
    std:: cout <<"size " << s.size() << "\n";

    //check empty:
    std::cout << "Check for empty " << std::boolalpha << s.empty() << "\n";

    std::cout << "top " << s.top() << "\n";

}