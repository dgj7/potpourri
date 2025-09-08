#ifndef __WM__DESTROY__EVENT__HANDLER__H__
#define __WM__DESTROY__EVENT__HANDLER__H__

#include <windows.h>

#include "../mswin/IEventHandler.hpp"

class WmDestroyEventHandler : public IEventHandler
{
public:
	virtual int handle(Event);
};

#endif
