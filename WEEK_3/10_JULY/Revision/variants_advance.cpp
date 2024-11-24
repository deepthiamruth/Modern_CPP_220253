#include<iostream>
#include<variant>

using VrType = std::variant <int, std::string> ;

//possible on all types for the variant 
void DisplayValue(VrType & v){
    std::visit ([] (auto&& val){std::cout << val << "\n";}, v);
}

void ConvertToUpperCase(VrType & v){
    if(std::holds_alternative<std::string>(v)){
        //access the string from its slot
        std::string temp = std::get<1>(v);
        for(char c : temp){
            std:: cout << char((int)c - 32) ;
        }
        std::cout << "\n";
    }
}
int main(){
    VrType v;
    v = "deepthi";
    DisplayValue(v);
    ConvertToUpperCase(v);
}
