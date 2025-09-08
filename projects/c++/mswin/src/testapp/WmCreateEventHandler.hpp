#ifndef __WM__CREATE__EVENT__HANDLER__H__
#define __WM__CREATE__EVENT__HANDLER__H__

#include <windows.h>

#include "../mswin/IEventHandler.hpp"
#include "../mswin/Event.hpp"
#include "../mswin/ControlConfig.hpp"
#include "../mswin/Control.hpp"
#include "../mswin/WindowFactory.hpp"

class WmCreateEventHandler : public IEventHandler
{
protected:
	ControlConfig createFirstButtonControlConfig();
	ControlConfig createSecondButtonControlConfig();
	ControlConfig createThirdButtonControlConfig();
	ControlConfig createConsoleEditBox();
public:
	virtual int handle(Event);
};

#endif
