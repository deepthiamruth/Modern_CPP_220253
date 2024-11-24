#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>



using VrType= std:: variant<BusinessOwner, Employee>;
void Display(const VrType& v){

    std:: visit ( [](auto && val){std:: cout << val << "\n"; } , v);
    
}
int main(){
    VrType vr;
    Employee e1 {"Deepthi", 9000.0f};
    BusinessOwner b1 {"Deepthi", 8374.0f};
    vr = e1;
    Display(vr);
    vr = b1;
    Display(vr);
}