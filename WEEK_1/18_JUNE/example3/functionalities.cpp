#include "functionalities.h"

void CreateObjects(Engine ** arr, int size){
    arr[0] = new Engine(10, 20, 2.3f);
    arr[1] = new Engine(34, 78, 90.8);
    arr[2] = new Engine(14, 67, 67.4);
}

void AverageHorsepower(Engine ** arr, int size){
    int total=0.0f;
    int valid_data = 0;
    for(int i=0;i<size;i++){
        if(arr[i]){
            total = total + arr[i] ->gethorsePower();
            valid_data++;
        }
    }
    std:: cout << "Average is: " << total/valid_data <<"\n";
}

float FindTorqueById(Engine ** arr, int size, int id){
    bool flag =false;
    bool valid_array = false;
    for(int i=0;i<size;i++){
        if(arr[i] && arr[i] -> getid() == id){
            flag = true;
            valid_array = true;
            std:: cout << "torque when id is given " << arr[i] -> gettorque() <<"\n";
            return arr[i] -> gettorque(); 
        }
    }
    if(!flag){
         throw IdNotFoundException("ID NOT FOUND\n");
    }
    if(!valid_array){
        throw NullPointerException("Array is Empty\n");
    }
   
    return 0.0;  
}

void FindHorsePowerForMinTorque(Engine ** arr, int size){
    float min = arr[0] -> gettorque();
    int idx=0;
    for(int i=0;i<size;i++){
        if(arr[i] && arr[i] -> gettorque() < min){
            min = arr[i] -> gettorque();
            idx = i;
        }
    }
    std:: cout << arr[idx] -> gethorsePower() << "\n";
}