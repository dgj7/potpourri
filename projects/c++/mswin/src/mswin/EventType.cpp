#include "EventType.hpp"

//EventTypes eventTypes;

EventType::EventType(int value, std::string name)
{
    type = std::make_pair(value,name);
}

std::string EventType::getName() const
{
    return type.second;
}

int EventType::getValue() const
{
    return type.first;
}
