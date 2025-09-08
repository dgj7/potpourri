#include "EventProcessor.hpp"

std::shared_ptr<EventProcessor> EventProcessor::instance;// = EventProcessor::getInstance();

EventProcessor::EventProcessor()
{
	//
}

int EventProcessor::processEvent(Event event, std::list<std::pair<EventType,std::shared_ptr<IEventHandler>>> queuedEventProcessors)
{
	HWND hwnd = event.getHwnd();
	std::shared_ptr<WindowEventProcessor> processor = getProcessor(hwnd);
	
	if(processor)
	{
		return processor->processEvent(event);
	}
	else
	{
		for(std::pair<EventType,std::shared_ptr<IEventHandler>> queuedPair : queuedEventProcessors)
		{
			if(queuedPair.first.getValue() == event.getUmsg())
			{
				return queuedPair.second->handle(event);
			}
		}
	}
	
	return DefWindowProc(event.getHwnd(), event.getUmsg(), event.getWparam(), event.getLparam());
}

void EventProcessor::addProcessor(HWND hwnd, std::shared_ptr<WindowEventProcessor> windowProcessor)
{
	HwndKey key = createHwndKey(hwnd);
	windowProcessors[key] = windowProcessor;
}

std::shared_ptr<WindowEventProcessor> EventProcessor::getProcessor(HWND hwnd)
{
	HwndKey key = createHwndKey(hwnd);
	std::map<HwndKey,std::shared_ptr<WindowEventProcessor>>::iterator it = windowProcessors.find(key);
	if(it != windowProcessors.end())
		return it->second;
	return nullptr;
}

std::shared_ptr<EventProcessor> EventProcessor::getInstance()
{
	if(!instance)
		instance = std::shared_ptr<EventProcessor>(new EventProcessor());
	return instance;
}
