#include "WmCloseEventHandler.hpp"

int WmCloseEventHandler::handle(Event event)
{
	MessageBox(NULL, "handling WM_CLOSE...", "Status", MB_ICONEXCLAMATION | MB_OK);
	DestroyWindow(event.getHwnd());
	return 0;
}