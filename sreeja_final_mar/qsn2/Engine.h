#ifndef ENGINE_H
#define ENGINE_H

#include "EngineType.h"

#include <iostream>
#include <vector>

class Engine
{
private:
    std::string m_engine_id {""};
    unsigned int m_engine_hp {0};
    float m_engine_torque {0.0f};
    EngineType m_engine_type {EngineType::REGULAR};
    float m_engine_cc {0.0f};

public:
    Engine() = default;
    ~Engine() = default;
    Engine(const Engine&) = default;
    Engine(Engine&& ) = default;
    Engine& operator = (const Engine&) = default;
    Engine& operator = (Engine&& ) = default;

    Engine(std::string id, unsigned int hp, float torque, EngineType type, float cc);

    std::string engineId() const { return m_engine_id; }

    unsigned int engineHp() const { return m_engine_hp; }

    float engineTorque() const { return m_engine_torque; }

    EngineType engineType() const { return m_engine_type; }

    float engineCc() const { return m_engine_cc; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "m_engine_id: " << rhs.m_engine_id
           << " m_engine_hp: " << rhs.m_engine_hp
           << " m_engine_torque: " << rhs.m_engine_torque
           << " m_engine_type: " << (int) rhs.m_engine_type
           << " m_engine_cc: " << rhs.m_engine_cc;
        return os;
    }
};



#endif // ENGINE_H
