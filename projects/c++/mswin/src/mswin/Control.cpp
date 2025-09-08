#include "Control.hpp"

Control::Control()
{
	//
}

HWND Control::getHwnd() const
{
	return hwnd;
}

void Control::build(ControlConfig controlConfig, HWND parentHwnd, int controlCount)
{
	controlId = controlCount + 1;
	HWND tmpHwnd = CreateWindowEx(
		controlConfig.getDwExStyle(),
		(controlConfig.getWindowClass().empty() ? NULL : controlConfig.getWindowClass().c_str()),
		(controlConfig.getControlText().empty() ? NULL : controlConfig.getControlText().c_str()),
		controlConfig.getDwStyle(),
		controlConfig.getXPos(),
		controlConfig.getYPos(),
		controlConfig.getWidth(),
		controlConfig.getHeight(),
		parentHwnd,
		(HMENU)controlId,
		(HINSTANCE)GetWindowLong(parentHwnd,GWL_HINSTANCE),
		NULL /* always null */
	);
	
	if(tmpHwnd == NULL)
	{
		throw CreateWindowException(ErrorMessageConstants::CONTROL_CREATION_ERROR_MESSAGE);
	}
	
	hwnd = tmpHwnd;
}

std::string Control::getControlName() const
{
	return controlName;
}

void Control::setControlName(std::string input)
{
	controlName = input;
}

int Control::getControlId() const
{
	return controlId;
}
