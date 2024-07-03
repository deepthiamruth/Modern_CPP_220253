// we can avoid writing exceptions using optional
#include <iostream>
#include <optional>
//Factorial takes 1 int16_t by value and optionally returns a size_t (sometimes, not always) //or factorial func may or maynor return a value
std:: optional <size_t> Factorial(int16_t val){
    size_t total {1};
    if(val<0){
        return std:: nullopt; // a symbolic data value to indicate "null"
    }
    if(val == 0 || val ==1){
        return 1;
    }
    else{
        size_t total {1};
        for(size_t i =2; i<= val; i++){
            total +=i;
        }
        return total;
    }
}
int main(){
    // try{
    //     Factorial(10);
    // }catch(std:: invalid_argument & ex){
    //     std:: cerr << ex.what()<< "\n";
    // }

   if(std:: optional <size_t> result = Factorial(-5); result.has_value()){
    std:: cout << "Factorial is" << result.value();
   }
    else{
        std:: cerr <<"factorial did not return a value\n";
    }
}