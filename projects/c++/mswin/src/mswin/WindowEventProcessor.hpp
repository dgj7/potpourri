#ifndef __WINDOW__EVENT__PROCESSOR__H__
#define __WINDOW__EVENT__PROCESSOR__H__

#include <map>
#include <memory>

#include <windows.h>

#include "IEventHandler.hpp"
#include "EventType.hpp"
#include "Event.hpp"

class WindowEventProcessor
{
protected:
	std::map<long,std::shared_ptr<IEventHandler>> eventHandlers;
public:
	WindowEventProcessor();
	
	void addHandler(EventType,std::shared_ptr<IEventHandler>);
	std::shared_ptr<IEventHandler> getHandler(long);
	
	int processEvent(Event);
};

#endif
