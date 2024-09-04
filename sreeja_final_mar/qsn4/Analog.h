#ifndef ANALOG_H
#define ANALOG_H

#include <iostream>
#include <vector>

#include "SystemType.h"
#include "ProtocolType.h"

class Analog
{
private:
    std::string m_system_id{""};
    SystemType m_system_type {SystemType::BLUETOOTH};
    std::vector<ProtocolType> m_protocol_support {};
    bool m_usb_3_supprt {false};


public:
    Analog() = default;
    ~Analog() = default;
    Analog(const Analog&) = delete;
    Analog(Analog&&) = delete;
    Analog& operator = (const Analog&) = delete;
    Analog& operator = (Analog&&) = delete;

    Analog(std::string sid, SystemType sType, std::vector<ProtocolType> protocol, bool usb);

    std::string systemId() const { return m_system_id; }

    SystemType systemType() const { return m_system_type; }

    std::vector<ProtocolType> protocolSupport() const { return m_protocol_support; }

    friend std::ostream &operator<<(std::ostream &os, const Analog &rhs) {
        os << "m_system_id: " << rhs.m_system_id
           << " m_system_type: " << (int) rhs.m_system_type
           << " m_usb_3_supprt: " << rhs.m_usb_3_supprt;
        return os;
    }
};



#endif // ANALOG_H
