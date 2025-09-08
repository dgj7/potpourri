#ifndef __LOGGER__H__
#define __LOGGER__H__

#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "LogLevel.hpp"
#include "LoggerConfiguration.hpp"
#include "LoggedFileName.hpp"

class Logger
{
protected:
    LoggedFileName loggedFileName;
    void log(LogLevel,std::string);
public:
    void error(std::string);
    void warn(std::string);
    void info(std::string);
    void debug(std::string);
    void trace(std::string);
	
	Logger(std::string);
	
	void addAppender(std::shared_ptr<ILogAppender>);
    void setFormatter(std::shared_ptr<ILogFormatter>);
	void setCurrentLogLevel(LogLevel);
};

#endif // __LOGGER__H__
