#include <iostream>
#include<memory>
#include<Employee.h>



void Destination(int n1){

}

void Forward(int n1){
    Destination(n1);
}


int main(){

    Forward(10);


    //std::shared_ptr<Employee> sptr = std::make_shared<Employee> (103, "deepthi", 14087.0f, 22, 0.4f);
    //take 5 parameters and convert it into the given type(Employee) and created in heap

}


/*

    What is Forwarding function , how to recognize it?
    A forwarding function is a template function that accepts parameters to call function F.

    It will always be a variadic template

    It will always use the built in tool std::forward

    All parameters received in the function shall be of type "Something" with the syntax <function-name> (Something&&... values)

    i.e The function shall receive one or more template parameters using ... with &&

    make_shared is a forwarded function
*/

/*
    void Magic(int&& data);

    template <typename T>
    void Magic(T&& data); //T&& does not mean r value , it means forwarded function
*/




//---------------------------------------------------------------------------------------------
/*
    1) THIS IS AN ASSIGNMENT OPERATION : RHS HAS TO BE ASSIGNED TO LHS!
    RHS IS EXECUTED FIRST

    2) RHS IS A FUNCTION . FUNCTIONS ARE CALLED WITH PARAMETERS
*/