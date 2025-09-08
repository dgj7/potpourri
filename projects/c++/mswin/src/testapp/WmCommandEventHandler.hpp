#ifndef __WM__COMMAND__EVENT__HANDLER__H__
#define __WM__COMMAND__EVENT__HANDLER__H__

#include <memory>

#include <windows.h>

#include "../mswin/IEventHandler.hpp"
#include "../mswin/WindowRegistry.hpp"

class WmCommandEventHandler : public IEventHandler
{
public:
	virtual int handle(Event);
};

#endif
