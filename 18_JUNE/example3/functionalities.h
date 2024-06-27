#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Engine.h"
#include "IdNotFoundException.h"
#include "NullPointerException.h"
void CreateObjects(Engine ** , int );
void AverageHorsepower(Engine ** , int );
float FindTorqueById(Engine ** , int , int );
void FindHorsePowerForMinTorque(Engine ** , int );

#endif // FUNCTIONALITIES_H
