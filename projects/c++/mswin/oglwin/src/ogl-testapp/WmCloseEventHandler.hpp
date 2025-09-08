#ifndef __WM__CLOSE__EVENT__HANDLER__H__
#define __WM__CLOSE__EVENT__HANDLER__H__

#include <windows.h>

#include "../mswin/IEventHandler.hpp"

class WmCloseEventHandler : public IEventHandler
{
public:
	virtual int handle(Event);
};

#endif
