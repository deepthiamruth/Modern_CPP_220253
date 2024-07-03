/*
    keep data on heap
    and use variant for "functional polymorphism"
*/

#include <iostream>
#include <variant>
#include "Employee.h"
#include "BusinessOwner.h"

/*
    A function which either accepts another function as a parameter or returns a function is called "Higher-order" function
*/

// works even copy constructions are disabled because we are passing the reference
using VrType = std:: variant <BusinessOwner* , Employee*>;

void Display(const VrType & v){
    std:: visit ([](auto && val){std:: cout << *val << "\n";}, v );
}


// if v holds alternative of type employee* fetch the data from that slot and take action
void showPfAmount(const VrType & v){
    if(std:: holds_alternative <Employee*>(v)){
        Employee* e = std::get<1> (v);
        e->CalculateMonthlyPf();
    }
    throw std:: runtime_error("Not a valid for BusinessOwner type data");
}

void showTaxAmount(const VrType vr){
    std:: visit ([] (auto && val){val->CalculateTaxAmount();}, vr);
}
int main(){
    VrType vr;
    vr = new BusinessOwner {"Deepthi", 9000.0f};

    Display(vr);

    vr = new Employee { "Deepthi", 03984.0f};

    Display(vr);

    try{
        showPfAmount(vr);
    }
}

