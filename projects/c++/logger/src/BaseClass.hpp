#ifndef __BASE__CLASS__H__
#define __BASE__CLASS__H__

#include "logger/Logger.hpp"

class BaseClass
{
private:
	Logger logger = Logger("BaseClass");
public:
	BaseClass();
	virtual ~BaseClass();
};

#endif
