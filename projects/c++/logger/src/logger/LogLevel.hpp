#ifndef __LOG__LEVEL__H__
#define __LOG__LEVEL__H__

#include <utility>
#include <string>

class LogLevel
{
friend class LogLevels;
protected:
    std::pair<int,std::string> level;
    LogLevel(int,std::string);
public:
    std::string getName() const;
    int getValue() const;
};

class LogLevels
{
public:
    LogLevel Error = LogLevel(1, "ERROR");
    LogLevel Warn = LogLevel(2, "WARN");
    LogLevel Info = LogLevel(3, "INFO");
    LogLevel Debug = LogLevel(4, "DEBUG");
    LogLevel Trace = LogLevel(5, "TRACE");
};

extern LogLevels logLevels;

#endif // __LOG__LEVEL__H__
