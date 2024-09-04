#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarType.h"
#include "EmissionCategory.h"

class Car
{
private:
    std::string m_reg_id {""};
    unsigned int m_emmison_category {0};
    float m_chassis_length {0.0f};
    CarType m_carType {CarType::OTHER};
    float m_seatCount{0.0f};

public:
    Car() = default;
    ~Car() = default;
    Car(const Car&) = delete;
    Car(Car&&) = delete;
    Car& operator = (const Car&) = delete;
    Car& operator = (Car&&) = delete;

    Car(std::string id, unsigned int category, float length, CarType cartype, float seatcount);

    std::string regId() const { return m_reg_id; }

    unsigned int emmisonCategory() const { return m_emmison_category; }

    float chassisLength() const { return m_chassis_length; }

    CarType carType() const { return m_carType; }

    float seatCount() const { return m_seatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_reg_id: " << rhs.m_reg_id
           << " m_emmison_category: " << rhs.m_emmison_category
           << " m_chassis_length: " << rhs.m_chassis_length
           << " m_carType: " << (int) rhs.m_carType
           << " m_seatCount: " << rhs.m_seatCount;
        return os;
    }
};


#endif // CAR_H
