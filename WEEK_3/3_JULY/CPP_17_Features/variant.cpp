#include <iostream>
#include <vector>
#include <variant>


// varients : are categorical types which allows "either or" principle of
int main(){
    int32_t n1{100};
    std:: string s1 {"Deepthi"};
    std:: variant<int32_t, std::string> vr;
    
    vr = n1; // n1 is assigned to variant
    //std::cout<< vr << "\n";
    std:: cout << "Variant is working\n";

    vr=s1;

    vr=89.0f;
}