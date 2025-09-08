#include "StdOutLogAppender.hpp"

void StdOutLogAppender::doLogging(std::string message)
{
    std::cout << message;
}