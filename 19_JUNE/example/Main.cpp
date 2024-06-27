#include "Functionalities.h"
#include "IdNotFoundException.h"
#include "NullArrayException.h"


int main() {
   // Engine* engines[3];
    std::vector <Engine*>engines; 
    CreateObjects(engines);
    try {
    AverageHorsePower(engines);
    }
    catch (NullArrayException& ex) {
        std::cerr << ex.what();
    }
    try {
    FindTorqueById(engines, 101);
    }
    catch(IdNotFoundException& ex) {
        std::cerr << ex.what();
    }
    catch(NullArrayException& ex) {
        std::cerr << ex.what();
    }
    try {
    FindHorsePowerForMinTorqueEngine(engines);
    }
    catch(NullArrayException& ex) {
        std::cerr << ex.what();
    }

}