#include <iostream>
bool CheckDivisibilityBy3(int32_t number){
    return number%3==0;
}
int main(){
    int32_t n1{12};

    //if flag is initialized and then flag is also true
    if(bool flag = CheckDivisibilityBy3(n1); flag){
        std:: cout << "number is divisible by 3\n";
    }
    else{
        std:: cerr << "Flag is set at :" << std:: boolalpha << flag << " Number not divisible by 3\n";
    }

    std:: cout << "Cannot access flag\n" ;
}