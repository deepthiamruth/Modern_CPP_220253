#include <iostream>
#include <functional>

void add(int32_t n1 , int32_t n2){
    std:: cout << n1+n2 << "\n";
}

int main(){

    int data= 20;
    int value = 200;


    //lambda object is bound to fn variable in the scope of main function
   auto fn = [](int32_t n1, int32_t n2){std:: cout << n1+n2 << "\n"; };

    //auto fn = [](int32_t n1, int32_t n2){std:: cout << n1+n2 + data << "\n"; }; // error because data is not in the lambda scope

    auto fn = [](int32_t n1 , int32_t n2 , int data ){std:: cout << n1+n2+data << "\n" ;} ;

    auto fn = [data](int32_t n1, int32_t n2){std:: cout << n1+n2 + data << "\n"; }; // captured by lambda

    auto fn = [data, value] (int32_t n1 , int32_t n2) {std:: cout << n1+ n2+data + value << "\n";};

    //fn(10,20, data); // overload () operator of a class created in the background

    fn (10,20);
}
