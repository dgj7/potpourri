#include "WmDestroyEventHandler.hpp"

int WmDestroyEventHandler::handle(Event event)
{
	MessageBox(NULL, "handling WM_DESTROY...", "Status", MB_ICONEXCLAMATION | MB_OK);
	PostQuitMessage(0);
	return 0;
}