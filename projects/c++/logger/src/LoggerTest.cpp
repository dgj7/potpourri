#include <iostream>
#include <memory>

#include "logger/Logger.hpp"
#include "LoggerConfigurator.hpp"

#include "BaseClass.hpp"

int main(int argc, char **argv)
{
	loggerConfigurator.configure();
	Logger logger("LoggerTest");
	logger.debug("begin test.");
	
	logger.trace("trace message, SHOULD NOT appear.");
	logger.info("info message, should appear.");
	logger.error("error message, should appear.");
	logger.warn("warn message, should appear.");
	
	BaseClass baseClass;
	
	
	logger.debug("end test.");
}