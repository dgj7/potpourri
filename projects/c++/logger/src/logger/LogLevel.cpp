#include "LogLevel.hpp"

LogLevels logLevels;

LogLevel::LogLevel(int value, std::string name)
{
    level = std::make_pair(value,name);
}

std::string LogLevel::getName() const
{
    return level.second;
}

int LogLevel::getValue() const
{
    return level.first;
}