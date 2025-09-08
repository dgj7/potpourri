#ifndef __DEFAULT__LOG__FORMATTER__H__
#define __DEFAULT__LOG__FORMATTER__H__

#include <string>
#include <ctime>

#include "LogLevel.hpp"
#include "LoggedFileName.hpp"
#include "StringUtils.hpp"
#include "ILogFormatter.hpp"

class DefaultLogFormatter : public ILogFormatter
{
public:
    std::string format(LogLevel,LoggedFileName,std::string);
protected:
	std::string createTimestamp();
};

#endif // __DEFAULT__LOG__FORMATTER__H__
