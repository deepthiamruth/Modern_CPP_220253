#ifndef DIGITAL_H
#define DIGITAL_H

#include <iostream>

#include "ConnectType.h"

class Digital
{
private:
    std::string m_system_id {""};
    ConnectType m_smart_connect_type {ConnectType::ANDROID_AUTO};
    float m_touch_screen_size {0.0f};
    bool m_5g_support;
public:
    Digital() = default;
    ~Digital() = default;
    Digital(const Digital&) = default;
    Digital(Digital&&) = default;
    Digital& operator = (const Digital&) = default;
    Digital& operator = (Digital&&) = default;

    Digital(std::string sid, ConnectType connectType, float screen_size, bool support5g);

    std::string systemId() const { return m_system_id; }

    ConnectType smartConnectType() const { return m_smart_connect_type; }

    float touchScreenSize() const { return m_touch_screen_size; }

    bool _5gSupport() const { return m_5g_support; }

    friend std::ostream &operator<<(std::ostream &os, const Digital &rhs) {
        os << "m_system_id: " << rhs.m_system_id
           << " m_smart_connect_type: " << (int) rhs.m_smart_connect_type
           << " m_touch_screen_size: " << rhs.m_touch_screen_size
           << " m_5g_support: " << rhs.m_5g_support;
        return os;
    }

};


#endif // DIGITAL_H
