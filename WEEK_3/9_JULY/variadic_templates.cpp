/*
    cpp11: create a function in cpp that can accept 1 or more arguments
*/

#include <iostream>
//base case : only 1 argument for addition

template <typename T>
T add(T val){
    return val;
}

template <typename T , typename... Other>//ellipsis operator
auto add(T n1, Other... args){
    return n1+ add(args...);}

int main(){
    std:: cout << add<int> (1,2,3) << "\n"; //6
    std:: cout << add<std::string> ("hello", "world") << "\n"; //1
    std:: cout << add<int> (1,2) << "\n"; //3
}