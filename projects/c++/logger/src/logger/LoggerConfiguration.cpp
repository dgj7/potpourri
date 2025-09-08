#include "LoggerConfiguration.hpp"
#include <iostream>

std::shared_ptr<LoggerConfiguration> LoggerConfiguration::instance;

bool LoggerConfiguration::isLoggable(LogLevel logLevel)
{
	if(currentLogLevel.getValue() >= logLevel.getValue())
        return true;
    return false;
}

void LoggerConfiguration::addAppender(std::shared_ptr<ILogAppender> appender)
{
    appenders.push_back(appender);
}

std::vector<std::shared_ptr<ILogAppender>> LoggerConfiguration::getAppenders() const
{
    return appenders;
}

void LoggerConfiguration::setFormatter(std::shared_ptr<ILogFormatter> fmtr)
{
    formatter = fmtr;
}

std::shared_ptr<ILogFormatter> LoggerConfiguration::getFormatter() const
{
    return formatter;
}

std::shared_ptr<LoggerConfiguration> LoggerConfiguration::getInstance()
{
	if(!instance)
		instance = std::make_shared<LoggerConfiguration>();
	return instance;
}

void LoggerConfiguration::setCurrentLogLevel(LogLevel logLevel)
{
	currentLogLevel = logLevel;
}

LogLevel LoggerConfiguration::getCurrentLogLevel() const
{
	return currentLogLevel;
}