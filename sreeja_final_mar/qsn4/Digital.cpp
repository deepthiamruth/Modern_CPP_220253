#include "Digital.h"

Digital::Digital(std::string sid, ConnectType connectType, float screen_size, bool support5g)
: m_system_id{sid}, m_smart_connect_type{connectType}, m_touch_screen_size{screen_size}, m_5g_support{support5g}
{
}