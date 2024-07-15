#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include "EngineType.h"
class Engine{
    private:
        std::string m_id{""};
        enum EngineType m_engine_type{EngineType::ALTERNATE_FUEL};
        float m_engine_cc{0.0f};
        float m_engine_torque{0.0f};
        short unsigned int m_engine_horsepower{1};
    public:
        Engine() = default;
        ~Engine() = default;
        Engine(const Engine&) = delete;
        Engine(Engine&&) = delete;
        Engine& operator= (const Engine &) = delete;
        Engine& operator= (Engine&&) = delete;

        Engine(std::string id, EngineType type , float engine_cc ,float torque, int power );

        std::string getid() const { return m_id; }

        enum EngineType getengineType() const { return m_engine_type; }

        float getengineCc() const { return m_engine_cc; }

        int getengineHorsepower() const { return m_engine_horsepower; }

        float getengineTorque() const { return m_engine_torque; }

        friend std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
            os << "m_id: " << rhs.m_id
               << " m_engine_type: " << (int) rhs.m_engine_type
               << " m_engine_cc: " << rhs.m_engine_cc
               << " m_engine_torque: " << rhs.m_engine_torque
               << " m_engine_horsepower: " << rhs.m_engine_horsepower;
            return os;
        }

        
};

#endif // ENGINE_H
