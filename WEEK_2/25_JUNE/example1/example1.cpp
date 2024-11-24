#include<iostream>
#include <vector>

void Square(int32_t number){
    std:: cout << number* number<<"\n";
}

void Cube(int32_t number){
    std:: cout << number* number* number<<"\n";
}

void Adaptor(void (fn)(int32_t number),std:: vector<int32_t>&data){
    //for each number in data , run the function with the number
    for(int32_t val: data){
        (fn)(val);
    }
}



int main(){
    // //function ka pointer ---> address of a function
    // void (*ptr)(int32_t number)  = & Square;
    // void (*temp)(int32_t number) = & Cube;
    // (*temp)(10); // call cube function as cube of 1std:: vector <int32_t> data{1,2,3,4,5};
    // (*ptr)(9); // square function as square(9);



    std:: vector <int32_t> data{1,2,3,4,5};
    Adaptor(Cube, data);
    Adaptor(Square, data);

    // if user want they can design their own function and use its logic to process "data"
    //let's see in example 2

}