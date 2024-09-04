#include "Sensor.h"

Sensor::Sensor(std::string id, float reading, SensorType type):
m_sensor_id{id}, m_reading{reading}, m_sensor_type{type}
{
}

float Sensor::CalculateErrorDeviation()
{
    return 0.2f * this->reading();
}
