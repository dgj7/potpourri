#ifndef __LOGGER__CONFIGURATION__H__
#define __LOGGER__CONFIGURATION__H__

#include <vector>
#include <memory>

#include "LogLevel.hpp"
#include "ILogAppender.hpp"
#include "ILogFormatter.hpp"
#include "DefaultLogFormatter.hpp"

#define loggerConfig LoggerConfiguration::getInstance()

class LoggerConfiguration
{
protected:
    std::vector<std::shared_ptr<ILogAppender>> appenders;
    std::shared_ptr<ILogFormatter> formatter = std::make_shared<DefaultLogFormatter>();
    LogLevel currentLogLevel = logLevels.Error;
	static std::shared_ptr<LoggerConfiguration> instance;

public:
    bool isLoggable(LogLevel);
	
	static std::shared_ptr<LoggerConfiguration> getInstance();

    void addAppender(std::shared_ptr<ILogAppender>);
    std::vector<std::shared_ptr<ILogAppender>> getAppenders() const;

    void setFormatter(std::shared_ptr<ILogFormatter>);
    std::shared_ptr<ILogFormatter> getFormatter() const;
	
	void setCurrentLogLevel(LogLevel);
	LogLevel getCurrentLogLevel() const;
};

#endif // __LOGGER__CONFIGURATION__H__
