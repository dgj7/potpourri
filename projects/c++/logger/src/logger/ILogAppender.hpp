#ifndef __INTERFACE__LOG__APPENDER__H__
#define __INTERFACE__LOG__APPENDER__H__

#include <string>

class ILogAppender
{
public:
    virtual void doLogging(std::string) = 0;
};

#endif // __INTERFACE__LOG__APPENDER__H__
