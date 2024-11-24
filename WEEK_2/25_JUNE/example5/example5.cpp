#include <iostream>
#include <functional>
#include <vector>

void Magic(std:: function <void (const int32_t) > fn){
    fn(10);
}


//rule 3(part 1)
std:: function <void(int32_t) > Demo(){
    return [] (const int32_t val){
        return val* val * val * val;
    };
}


int main(){
    // Type of fn:
    /*
        a function which accepts one int_32t by value and return void
    */
   auto fn = [] (const int32_t val){
    std:: cout << val* val; } ;


    //rule 2
    Magic(fn); //works!



    //rule 3 part 2
    auto ans = Demo(); // accept the function returned in a variable


    //rule 4 
    auto temp = ans; //function copied 
    auto * ptr = &ans; // addressing also works!

    //rule 5 function can be saved in other containers
    std:: vector <   std:: function<void(int32_t)>   >fns{fn};


}