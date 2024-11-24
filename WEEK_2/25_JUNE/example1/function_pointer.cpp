#include<iostream>


void Square(int32_t number){
    std:: cout << number* number<<"\n";
}

void Cube(int32_t number){
    std:: cout << number* number* number<<"\n";
}
int main(){
    //function ka pointer ---> address of a function
    void (*ptr)(int32_t number)  = & Square;
    void (*temp)(int32_t number) = & Cube;

    (*temp)(10); // call cube function as cube of 10;
    (*ptr)(9); // square function as square(9);
}