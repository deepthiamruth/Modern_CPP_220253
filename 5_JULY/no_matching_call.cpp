//Demo is a function which takes 2  parameters of data type non const int by value and non const string by value which returns a void 

#include <iostream>
#include <thread>

void Formula(int & value ,  float factor , const std:: string & name){
    std::cout << "something";
}

int main(){
    int n1{10};
    std:: thread t1 {&Formula, std::ref (n1), 10.21f, "deepthi"};
    //thread req references in a wrapper ---->std::ref
    //const l value reference can take r value
}