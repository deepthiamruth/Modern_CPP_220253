#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include <vector>

//Vector of engine pointers
void CreateObjects(std::vector<Engine*>& engines);
float AverageHorsePower(const std::vector<Engine*>& engines);
int FindHorsePowerForMinTorqueEngine(const std::vector<Engine*>& engines);
float FindTorqueById(const std::vector<Engine*>& engines, int n);

#endif // FUNCTIONALITIES_H
 