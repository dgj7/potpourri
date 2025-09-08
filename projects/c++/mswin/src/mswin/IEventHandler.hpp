#ifndef __INTERFACE__EVENT__HANDLER__H__
#define __INTERFACE__EVENT__HANDLER__H__

#include "Event.hpp"

class IEventHandler
{
public:
	virtual int handle(Event) = 0;
};

#endif
