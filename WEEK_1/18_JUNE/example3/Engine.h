#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>

class Engine{
    private:
        int _id{0};
        int horse_power{0};
        float _torque{0.0f};
    public:
        Engine() = default;
        ~Engine() = default;
        Engine(const Engine& other) = delete;
        Engine(Engine && other) = delete;
        Engine& operator= (const Engine& other) = delete;
        Engine& operator = (Engine&& other) = delete;

        Engine(int id, int power , float torque);

        int getid() const { return _id; }
        void setId(int id) { _id = id; }

        int gethorsePower() const { return horse_power; }
        void setHorsePower(int horsePower) { horse_power = horsePower; }

        float gettorque() const { return _torque; }
        void setTorque(float torque) { _torque = torque; }

};




#endif // ENGINE_H
