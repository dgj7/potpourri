#ifndef __EVENT__PROCESSOR__H__
#define __EVENT__PROCESSOR__H__

#include <map>
#include <memory>
#include <list>
#include <utility>

#include <windows.h>

#include "Event.hpp"
#include "WindowEventProcessor.hpp"
#include "StringUtils.hpp"
#include "HwndKey.hpp"

class EventProcessor
{
friend class Window;
protected:
	std::map<HwndKey,std::shared_ptr<WindowEventProcessor>> windowProcessors;
	static std::shared_ptr<EventProcessor> instance;
	
	EventProcessor();
public:
	static std::shared_ptr<EventProcessor> getInstance();
	
	void addProcessor(HWND,std::shared_ptr<WindowEventProcessor>);
	std::shared_ptr<WindowEventProcessor> getProcessor(HWND);

	int processEvent(Event,std::list<std::pair<EventType,std::shared_ptr<IEventHandler>>>);
};

#endif
