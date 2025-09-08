#include "Logger.hpp"

Logger::Logger(std::string loggedFile)
:loggedFileName(loggedFile)
{
    //
}

void Logger::error(std::string message)
{
    log(logLevels.Error, message);
}

void Logger::warn(std::string message)
{
    log(logLevels.Warn, message);
}

void Logger::info(std::string message)
{
    log(logLevels.Info, message);
}

void Logger::debug(std::string message)
{
    log(logLevels.Debug, message);
}

void Logger::trace(std::string message)
{
    log(logLevels.Trace, message);
}

void Logger::log(LogLevel logLevel, std::string inputMessage)
{
	if(loggerConfig->isLoggable(logLevel))
    {
        std::shared_ptr<ILogFormatter> formatter = loggerConfig->getFormatter();
        std::string outputMessage = formatter->format(logLevel,loggedFileName,inputMessage);
        outputMessage = "\n" + outputMessage;
        for(std::shared_ptr<ILogAppender> appender : loggerConfig->getAppenders())
        {
            appender->doLogging(outputMessage);
        }
    }
}

void Logger::addAppender(std::shared_ptr<ILogAppender> appender)
{
	loggerConfig->addAppender(appender);
}

void Logger::setFormatter(std::shared_ptr<ILogFormatter> formatter)
{
	loggerConfig->setFormatter(formatter);
}

void Logger::setCurrentLogLevel(LogLevel logLevel)
{
	loggerConfig->setCurrentLogLevel(logLevel);
}
