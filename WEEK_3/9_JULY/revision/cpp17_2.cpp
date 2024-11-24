#include<iostream>
#include<variant>
class A
{
private:
    /* data */
public:
    A(/* args */);
    ~A();
};

A::A(/* args */)
{
    std::cout << "A created\n";
}

A::~A()
{
    std::cout << "A destroyed\n";
}

class B
{
private:
    /* data */
public:
    B(/* args */);
    ~B();
};

B::B(/* args */)
{
    std:: cout << "B created\n";
}

B::~B()
{
    std::cout << "B destroyed\n";
}



int main(){
    std:: variant <A,B> v{};

    v = B{};
    std::cout << "Switch to A again:\n";

    v = A{};
}