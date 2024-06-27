#include "Project.h"

Project::Project(std::string id, unsigned int size , float budget){
    this-> _id = id;
    this-> _budget = budget;
    this-> _teamsize = size;
}
Project::~Project(){
    
}