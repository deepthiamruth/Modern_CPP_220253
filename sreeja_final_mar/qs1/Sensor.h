#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include "SensorType.h"

class Sensor
{
private:
    std::string m_sensor_id {""};
    float m_reading {0.0f};
    SensorType m_sensor_type {SensorType::EMPLACED};
public:
    Sensor() = default;
    ~Sensor() = default;
    Sensor(const Sensor&) = default;
    Sensor(Sensor&&) = delete;
    Sensor& operator = (const Sensor&) = delete;
    Sensor& operator = (Sensor&&) = delete;

    Sensor(std::string id, float reading, SensorType type);

    float CalculateErrorDeviation();

    float operator+( Sensor& other) {
        return this->m_reading + other.m_reading;
    }

    std::string sensorId() const { return m_sensor_id; }

    float reading() const { return m_reading; }

    SensorType sensorType() const { return m_sensor_type; }
};


#endif // SENSOR_H
