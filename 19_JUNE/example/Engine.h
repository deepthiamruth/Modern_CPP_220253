#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

class Engine {
    private:
    unsigned int m_id{0};
    unsigned int m_horsePower{0};
    float m_torque{0.0f};

    public:
    Engine() = default;
    ~Engine() = default;
    Engine(const Engine& other) = default;
    Engine& operator = (const Engine& other) = delete;
    Engine(Engine&& other) = delete;
    Engine operator = (Engine&& other) = delete;

    Engine(unsigned int id, unsigned int horsePower, float torque);
    //: m_id {id}, m_torque{torque}, m_horsePower{horsePower} {}

    unsigned int horsePower() const { return m_horsePower; }

    unsigned int id() const { return m_id; }

    float torque() const { return m_torque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_horsePower: " << rhs.m_horsePower
           << " m_torque: " << rhs.m_torque;
        return os;
    }

};

#endif // ENGINE_H
