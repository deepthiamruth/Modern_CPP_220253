#include "functionalities.h"
#include <iostream>

int main(){
    Engine * arr[3];
    CreateObjects(arr, 3 );
    AverageHorsepower(arr , 3 );
    try{
    FindTorqueById(arr , 3 , 10);
    }catch(IdNotFoundException & ex){
        std:: cerr << ex.what();
    }
    FindHorsePowerForMinTorque(arr , 3 );
}