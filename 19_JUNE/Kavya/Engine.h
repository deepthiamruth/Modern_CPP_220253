#ifndef ENGINE_H
#define ENGINE_H

#include "IDNotFoundException.h"
#include "NullPointerException.h"
#include <iostream>
class Engine
{
private:
    int _id{0};
    int _horsePower{0};
    float _torque{0.0f};
public:

    Engine()=default;
    Engine(const Engine& other)=delete;
    Engine& operator=(const Engine& other)=delete;
    Engine(Engine&& other)=delete;//move constructor
    Engine& operator=(Engine&& other)=delete;
    Engine(int id,int power,float torque);
    ~Engine()=default;

    int horsePower() const { return _horsePower; }

    int id() const { return _id; }

    float torque() const { return _torque; }
};

#endif // ENGINE_H
