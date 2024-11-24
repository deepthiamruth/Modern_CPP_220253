#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include <vector>

using Container = std:: vector<Engine*>;

void createobjects(Container& ,unsigned int N);
//float averagehorsepower(const Container&,unsigned int N);
float averagehorsepower(std:: vector<Engine*> & ,unsigned int N);
float findtorquebyid(const Container&, unsigned int N, int ID);
int FindHorsePowerForMinTorqueEngine(const Container& ,unsigned int N);

#endif // FUNCTIONALITIES_H 
