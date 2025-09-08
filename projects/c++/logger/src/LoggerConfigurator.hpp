#ifndef __LOGGER__CONFIGURATOR__H__
#define __LOGGER__CONFIGURATOR__H__

#include "logger/LogLevel.hpp"
#include "logger/StdOutLogAppender.hpp"
#include "logger/Logger.hpp"

class LoggerConfigurator
{
private:
	Logger logger = Logger("LoggerConfigurator");
public:
	LoggerConfigurator();
	void configure();
};

extern LoggerConfigurator loggerConfigurator;

#endif
