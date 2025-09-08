#include "LoggerConfigurator.hpp"

LoggerConfigurator loggerConfigurator;

LoggerConfigurator::LoggerConfigurator()
{
	//
}

void LoggerConfigurator::configure()
{
	logger.setCurrentLogLevel(logLevels.Debug);
	logger.addAppender(std::make_shared<StdOutLogAppender>());
	logger.debug("finished configuring logger.");
}