#include "WindowConfig.hpp"

WindowConfig::WindowConfig()
{
	/* default values */
	style = 0;
	cbClsExtra = 0;
	cbWndExtra = 0;
	hwndParent = NULL;
	hMenu = NULL;
	lpParam = NULL;
	fullscreen = false;
}

HINSTANCE WindowConfig::getHInstance() const
{
	return hInstance;
}

void WindowConfig::setHInstance(HINSTANCE hi)
{
	hInstance = hi;
}

HINSTANCE WindowConfig::getHPrevInstance() const
{
	return hPrevInstance;
}

void WindowConfig::setHPrevInstance(HINSTANCE hpi)
{
	hPrevInstance = hpi;
}

std::string WindowConfig::getWindowTitle() const
{
	return windowTitle;
}

void WindowConfig::setWindowTitle(std::string title)
{
	windowTitle = title;
}

int WindowConfig::getNCmdShow() const
{
	return nCmdShow;
}

void WindowConfig::setNCmdShow(int n)
{
	nCmdShow = n;
}

int WindowConfig::getWidth() const
{
	return width;
}

void WindowConfig::setWidth(int w)
{
	width = w;
}

int WindowConfig::getHeight() const
{
	return height;
}

void WindowConfig::setHeight(int h)
{
	height = h;
}

std::string WindowConfig::getClassName() const
{
	return className;
}

void WindowConfig::setClassName(std::string input)
{
	className = input;
}

std::string WindowConfig::getMenuName() const
{
	return menuName;
}

void WindowConfig::setMenuName(std::string input)
{
	menuName = input;
}

UINT WindowConfig::getCbSize() const
{
	return cbSize;
}

void WindowConfig::setCbSize(UINT input)
{
	cbSize = input;
}

UINT WindowConfig::getStyle() const
{
	return style;
}

void WindowConfig::setStyle(UINT input)
{
	style = input;
}

int WindowConfig::getCbClsExtra() const
{
	return cbClsExtra;
}

void WindowConfig::setCbClsExtra(int input)
{
	cbClsExtra = input;
}

int WindowConfig::getCbWndExtra() const
{
	return cbWndExtra;
}

void WindowConfig::setCbWndExtra(int input)
{
	cbWndExtra = input;
}

HICON WindowConfig::getHIcon() const
{
	return hIcon;
}

void WindowConfig::setHIcon(HICON input)
{
	hIcon = input;
}

HICON WindowConfig::getHIconSm() const
{
	return hIconSm;
}

void WindowConfig::setHIconSm(HICON input)
{
	hIconSm = input;
}

HCURSOR WindowConfig::getHCursor() const
{
	return hCursor;
}

void WindowConfig::setHCursor(HCURSOR input)
{
	hCursor = input;
}

HBRUSH WindowConfig::getHbrBackground() const
{
	return hbrBackground;
}

void WindowConfig::setHbrBackground(HBRUSH input)
{
	hbrBackground = input;
}

DWORD WindowConfig::getDwExStyle() const
{
	return dwExStyle;
}

void WindowConfig::setDwExStyle(DWORD input)
{
	dwExStyle = input;
}

DWORD WindowConfig::getDwStyle() const
{
	return dwStyle;
}

void WindowConfig::setDwStyle(DWORD input)
{
	dwStyle = input;
}

int WindowConfig::getXWinPos() const
{
	return xWinPos;
}

void WindowConfig::setXWinPos(int input)
{
	xWinPos = input;
}

int WindowConfig::getYWinPos() const
{
	return yWinPos;
}

void WindowConfig::setYWinPos(int input)
{
	yWinPos = input;
}

HWND WindowConfig::getHwndParent() const
{
	return hwndParent;
}

void WindowConfig::setHwndParent(HWND input)
{
	hwndParent = input;
}

HMENU WindowConfig::getHMenu() const
{
	return hMenu;
}

void WindowConfig::setHMenu(HMENU input)
{
	hMenu = input;
}

LPVOID WindowConfig::getLpParam() const
{
	return lpParam;
}

void WindowConfig::setLpParam(LPVOID input)
{
	lpParam = input;
}

bool WindowConfig::isFullscreen() const
{
	return fullscreen;
}

void WindowConfig::setFullscreen(bool input)
{
	fullscreen = input;
}

std::list<std::pair<EventType,std::shared_ptr<IEventHandler>>> WindowConfig::getLstEventHandlers() const
{
	return lstEventHandlers;
}

void WindowConfig::addEventHandler(EventType eventType,std::shared_ptr<IEventHandler> handler)
{
	std::pair<EventType,std::shared_ptr<IEventHandler>> pairHandler(eventType,handler);
	lstEventHandlers.push_back(pairHandler);
}

void WindowConfig::addPhaseBehavior(WindowPhase windowPhase, std::shared_ptr<IWindowPhaseBehavior> behavior)
{
	if(behavior)
	{
		phaseBehaviors[windowPhase.getValue()] = behavior;
	}
}

std::shared_ptr<IWindowPhaseBehavior> WindowConfig::getPhaseBehavior(WindowPhase windowPhase)
{
	std::map<int,std::shared_ptr<IWindowPhaseBehavior>>::iterator it = phaseBehaviors.find(windowPhase.getValue());
	if(it != phaseBehaviors.end())
		return it->second;
	return nullptr;
}
