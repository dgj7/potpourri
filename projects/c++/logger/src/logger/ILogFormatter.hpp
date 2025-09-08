#ifndef __INTERFACE__LOGGER__FORMATTER__H__
#define __INTERFACE__LOGGER__FORMATTER__H__

#include <string>

#include "LogLevel.hpp"
#include "LoggedFileName.hpp"

class ILogFormatter
{
public:
    virtual std::string format(LogLevel,LoggedFileName,std::string) = 0;
protected:
	virtual std::string createTimestamp() = 0;
};

#endif // __INTERFACE__LOGGER__FORMATTER__H__
