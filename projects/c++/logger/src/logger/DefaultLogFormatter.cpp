#include "DefaultLogFormatter.hpp"

std::string DefaultLogFormatter::format(LogLevel logLevel, LoggedFileName loggedFileName, std::string input)
{
    std::string timestamp = createTimestamp();
    std::string output = timestamp + " " + logLevel.getName() + " " + loggedFileName.getFileName() + ": " + input;
    return output;
}

std::string DefaultLogFormatter::createTimestamp()
{
	time_t t = time(0);
    struct tm * now = localtime(&t);
    std::string output =
        to_std_string(now->tm_mon + 1)
        + std::string("/")
        + to_std_string(now->tm_mday)
        + std::string("/")
        + to_std_string(now->tm_year + 1900)
        + std::string(" ")
        + to_std_string(now->tm_hour)
        + std::string(":")
        + to_std_string(now->tm_min)
        + std::string(":")
        + to_std_string(now->tm_sec)
        ;

    return output;
}