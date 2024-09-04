#include "Engine.h"

Engine::Engine(std::string id, unsigned int hp, float torque, EngineType type, float cc)
: m_engine_id{id}, m_engine_hp{hp}, m_engine_torque{torque}, m_engine_type{type}, m_engine_cc{cc}
{
}