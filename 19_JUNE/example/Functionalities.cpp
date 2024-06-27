#include "Functionalities.h"
#include "IdNotFoundException.h"
#include "NullArrayException.h"

/*
Whatever you write in emplaceback it should be a sufficient material
to make a new instance for the container of that specific type
TYpe: vector of engine pointers---> we need materials to make a new Engine
*/

void CreateObjects(std::vector<Engine*>& engines)
{

    engines.emplace_back(new Engine(101, 233, 456.8f));
    engines.emplace_back(new Engine(102, 785, 456.8f));
    engines.emplace_back(new Engine(103, 197, 456.8f));
    //engines.emplace_back(nullptr);
  
}
float AverageHorsePower(const std::vector<Engine *> &engines)
{
    unsigned int sum {0};
    unsigned int count {0};
    float average {0.0};
    bool valid_array {false};

    //c-style for loop works only for which has an index  (arrays/vaectors)
    // for(std::size_t i = 0; i<engines.size(); i++) {
    //     if(engines[i]) {
    //         count++;
    //         valid_array = true;
    //         sum = sum + engines[i]->horsePower();
    //     }
    // }

    //In modern cpp we use the range based loop or for-each loop
    /*
        For each const Engine pointer called e present in engines
    */
    for(const Engine* e : engines) {
        if(e) {
            sum = e->horsePower();
            valid_array = true;
        }
    }

    if(valid_array == true) {
        average = sum/count;
        std::cout <<"Average horsepower = " << average << "\n";
        return {average};
    }
    if(valid_array == false) {
        throw NullArrayException("Null pointer array is detected\n");
        return 0;
    }
    return {average};
}

int FindHorsePowerForMinTorqueEngine(const std::vector<Engine *> &engines)
{
    int min  {0};
    //int min = engines[0]->torque();
    int index  {0};
    bool valid_array {false};
    for(std::size_t i=0;i<engines.size();i++) {
        if(engines[i]) {
            valid_array = true;
            if(min < engines[i]->torque()) {
                min = engines[i]->torque();
                index = i;
            }
        }
    }
    if(valid_array == true) {
    std::cout << "Horsepower for minimum torque engine = " << engines[index]->horsePower() << "\n";
    return engines[index]->horsePower();
    }
    if(valid_array == false) {
        throw NullArrayException("Null pointer array is detected\n");
    }
    return {0};
}

float FindTorqueById(const std::vector<Engine *> &engines, int id)
{
    bool valid_id {false};
    bool valid_array {false};
    for(std::size_t i=0;i<engines.size();i++) {
        if(engines[i]) {
            valid_array = true;
            if(engines[i]->id()==id) {
            valid_id = true;
            std::cout << "Torque for the given engine id is = " << engines[i]->torque() << "\n";
            break;
        }
    }
    }
    if(valid_array == false) {
        throw NullArrayException("Null pointer array is detected\n");
    }
    if(valid_id==false) {
        throw IdNotFoundException("Provide a valid Id\n");
    }
    
    return 0;
}

// float AverageHorsePower(Engine** engines) {
//     unsigned int sum = 0;
//     unsigned int count = 0;
//     float average = 0.0;
//     bool valid_array = false;
//     for(unsigned int i = 0; i<3; i++) {
//         if(engines[i]) {
//             count++;
//             valid_array = true;
//             sum = sum + engines[i]->horsePower();
//         }
//     }
//     if(valid_array == true) {
//         average = sum/count;
//         std::cout <<"Average horsepower = " << average << "\n";
//         return sum/count;
//     }
//     if(valid_array == false) {
//         throw NullArrayException("Null pointer array is detected\n");
//         return 0;
//     }
//     return average;
// }

// int FindHorsePowerForMinTorqueEngine(Engine** engines) {
//     int min = 0;
//     //int min = engines[0]->torque();
//     int index = 0;
//     bool valid_array = false;
//     for(int i=0;i<3;i++) {
//         if(engines[i]) {
//             valid_array = true;
//             if(min < engines[i]->torque()) {
//                 min = engines[i]->torque();
//                 index = i;
//             }
//         }
//     }
//     if(valid_array == true) {
//     std::cout << "Horsepower for minimum torque engine = " << engines[index]->horsePower() << "\n";
//     return engines[index]->horsePower();
//     }
//     if(valid_array == false) {
//         throw NullArrayException("Null pointer array is detected\n");
//     }
//     return 0;
// }

// int FindTorqueById(Engine ** engines, int id)
// {
//     bool valid_id = false;
//     bool valid_array = false;
//     for(unsigned int i=0;i<3;i++) {
//         if(engines[i]) {
//             valid_array = true;
//             if(engines[i]->id()==id) {
//             valid_id = true;
//             std::cout << "Torque for the given engine id is = " << engines[i]->torque() << "\n";
//             break;
//         }
//     }
//     }
//     if(valid_array == false) {
//         throw NullArrayException("Null pointer array is detected\n");
//     }
//     if(valid_id==false) {
//         throw IdNotFoundException("Provide a valid Id\n");
//     }
    
//     return 0;
// }

