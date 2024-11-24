#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <iostream>
#include <list>
#include <memory>
#include "Engine.h"
#include <functional>
#include <optional>
#include <future>
using srd_ptr = std::shared_ptr <Engine>;
using DataContainer = std::list  <srd_ptr> ;
using Logic = std::function<bool(const srd_ptr&)>;


//create 5 objects of class engine on heap
void CreateObjects(DataContainer&);




//return matching instances
std::optional <DataContainer> ReturnMatchingInstance(const DataContainer objects,const Logic & fn);




//IsAtleastOneInstanceMatching
bool IsAtleastOneInstanceMatching(const DataContainer objects, const Logic & fn );




//Average Engine_cc
float FindAverage(DataContainer&);





#endif // FUNCTIONALITIES_H
