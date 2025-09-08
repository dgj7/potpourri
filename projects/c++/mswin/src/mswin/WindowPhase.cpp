#include "WindowPhase.hpp"

WindowPhase::WindowPhase(int value, std::string name)
{
    phase = std::make_pair(value,name);
}

std::string WindowPhase::getName() const
{
    return phase.second;
}

int WindowPhase::getValue() const
{
    return phase.first;
}
