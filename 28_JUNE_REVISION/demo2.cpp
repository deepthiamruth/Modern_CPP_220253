#include <iostream>
#include<functional>
void formula(int& x, int  y, int z){
    std:: cout << x+y+z << "\n";
}

int  main(){
    int a = 10;
    auto binded_formula = std:: bind(&formula, std:: ref(a) , 100 , std::placeholders ::_1);
    binded_formula(99); // formula (a,100,99)


    //create a reference wrapper
    std:: reference_wrapper <int> ref{a};
    binded_formula(99);

    // total waste // write std:: ref(a) in line 9

    //std:: ref takes a lvalue and immediately converts it into a reference wrapper



}