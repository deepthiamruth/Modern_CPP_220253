#include<iostream>
#include <functional>


using logic = std:: function <int32_t(int32_t)>;

auto Adaptor(logic fn , int32_t value)-> void{
    std:: cout << fn(value);
}
int main(){
    //takes one input of type int32_t by value and returns an int32_t 
    //function should multiply input number by 100

   auto fn = [] (int32_t n) -> int32_t {return n*100;};

    int n1=100;
    auto demo_fn = [n1] (int32_t num) { return num*n1;};

    // auto demo_fn = [n1] (int32_t num) mutable { n1 = 99 ;return num*n1;}; // you can modify n1 because its mutable

   Adaptor(fn , 10);
}