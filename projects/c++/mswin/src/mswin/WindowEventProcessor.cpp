#include "WindowEventProcessor.hpp"

WindowEventProcessor::WindowEventProcessor()
{
	//
}

void WindowEventProcessor::addHandler(EventType eventType, std::shared_ptr<IEventHandler> handler)
{
	eventHandlers[eventType.getValue()] = handler;
}

std::shared_ptr<IEventHandler> WindowEventProcessor::getHandler(long eventId)
{
	std::map<long,std::shared_ptr<IEventHandler>>::iterator it = eventHandlers.find(eventId);
	if(it != eventHandlers.end())
		return it->second;
	return nullptr;
}

int WindowEventProcessor::processEvent(Event event)
{
	std::shared_ptr<IEventHandler> handler = getHandler(event.getUmsg());
	if(handler)
		return handler->handle(event);
	return DefWindowProc(event.getHwnd(), event.getUmsg(), event.getWparam(), event.getLparam());
}
