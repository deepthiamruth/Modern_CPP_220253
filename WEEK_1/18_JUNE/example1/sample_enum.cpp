//----------------------------------
// PROBLEMS IN ENUM
#include <iostream>

enum Gear{
//enum class Gear{
    FIRST,
    SECOND
};
enum Rank{
    FIRST,
    SECOND
};
void Magic(int n1){
    std:: cout << n1*100;
}
int main(){

    FIRST; // problem 1 : not mandatory to prefix enum name (confusion)

    Gear g1 = Gear:: FIRST;
    Rank r1 = Rank :: FIRST;

    if(g1==r1){
        std:: cout << "nooooooooo"; //problems 2 enums of two diff categories get compared basis on integer
    }
    Magic(g1); // problem 3 : auto conversion of enum to integer without consent!
}
//-----------------------------------------------------------------------------------------

//to avoid the problems in enum use enum class