#include "Functionalities.h"


void createobjects(Container & engines,unsigned int N)
{  
     for(int i=0;i<N;i++){
        int _id;
        int _horsePower;
        float _torque;

        std::cin>>_id;
        std::cin>>_horsePower;
        std::cin>>_torque;

        engines[i]=new Engine(_id,_horsePower,_torque);
     }
}

float averagehorsepower(Engine **engines, unsigned int N)
{
    float total=0.0f;
    bool valid=false;
    unsigned short c=0;
    for(int i=0;i<N;i++){
        if(engines[i]){
            valid=true;
            c++;
            total=total+engines[i]->horsePower();
        }
    }
    if(valid){
        return total/c;
    }
    return -1.0f;
}

float findtorquebyid(Engine **engines, unsigned int N, int ID)
{
    bool isvalid=false;
    bool flag=false;
    for(int i=0;i<N;i++){
        if(engines[i]){
        if(engines[i]->id()==ID){
            isvalid=true;
            return engines[i]->torque();
        }
        flag=true;
    }
    }
    if(!flag){
        throw NullPointerException("null pointer\n");
    }
    if(!isvalid){
       throw IDNotFoundException("ID is not found\n");
    }
    return -1.0f;
}

int FindHorsePowerForMinTorqueEngine(Engine **engines, unsigned int N)
{
    int min=engines[0]->torque();
    int idx=0;
    bool isvalid=false;
    for(int i=0;i<N;i++){
         if(engines[i]->torque()<min){
             isvalid=true;
             min=engines[i]->torque();
             idx=i;
         }
    }
    return engines[idx]->horsePower();
}
