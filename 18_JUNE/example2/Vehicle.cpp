#include<iostream>
class Vehicle{
    private:
    std:: string m_id;
    std:: string m_modelName;
    public:
        Vehicle() = default; //default construction
        //Vehicle() = delete;
        ~Vehicle () = default;

        /*
            Vehicle constructor that takes one const lvalue reference to a vehicle as a parameter
        */
        //Vehicle(const Vehicle& other ) = delete;
        Vehicle(const Vehicle& other ) = default; // copyconstructor

        Vehicle (std:: string id, std:: string name) : m_id{id} , m_modelName{name} {}
};

int main(){
    Vehicle v1{"101", "DZire"};

    Vehicle v2{v1}; // get error when deleted v2[101 | DZire]

    int n1=10;
    int n2=21;
    n2=n1; // assingnment but not copying because n2 already existed


    Vehicle v3{};
    v3 = v1; // assigning 
}