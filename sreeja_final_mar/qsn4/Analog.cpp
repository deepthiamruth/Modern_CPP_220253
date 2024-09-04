#include "Analog.h"

Analog::Analog(std::string sid, SystemType sType, std::vector<ProtocolType> protocol, bool usb)
: m_system_id{sid}, m_system_type{sType}, m_protocol_support{protocol}, m_usb_3_supprt{usb}
{
}