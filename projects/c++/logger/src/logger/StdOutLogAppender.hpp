#ifndef __STD__OUT__LOG__APPENDER__H__
#define __STD__OUT__LOG__APPENDER__H__

#include <iostream>
#include <string>

#include "ILogAppender.hpp"

class StdOutLogAppender : public ILogAppender
{
public:
    void doLogging(std::string);
};

#endif // __STD__OUT__LOG__APPENDER__H__
