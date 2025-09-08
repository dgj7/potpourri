#include "WindowRegistry.hpp"

std::shared_ptr<WindowRegistry> WindowRegistry::instance;

WindowRegistry::WindowRegistry()
{
	//
}

std::shared_ptr<WindowRegistry> WindowRegistry::getInstance()
{
	if(!instance)
		instance = std::shared_ptr<WindowRegistry>(new WindowRegistry());
	return instance;
}

void WindowRegistry::addWindow(std::shared_ptr<Window> window)
{
	HwndKey hwndKey = createHwndKey(window->getHwnd());
	windowRegistry[hwndKey] = window;
}

std::shared_ptr<Window> WindowRegistry::locateWindow(HWND hwnd)
{
	HwndKey hwndKey = createHwndKey(hwnd);
	std::map<HwndKey,std::shared_ptr<Window>>::iterator it = windowRegistry.find(hwndKey);
	if(it != windowRegistry.end())
		return it->second;
	return nullptr;
}

std::list<std::shared_ptr<Control>> WindowRegistry::locateControls(HWND parentWindowHwnd)
{
	std::list<std::shared_ptr<Control>> emptyList;
	HwndKey hwndKey = createHwndKey(parentWindowHwnd);
	std::map<HwndKey,std::list<std::shared_ptr<Control>>>::iterator it = controlRegistry.find(hwndKey);
	if(it != controlRegistry.end())
		return it->second;
	return emptyList;
}

void WindowRegistry::addControl(std::shared_ptr<Control> control, HWND parentWindowHwnd)
{
	HwndKey hwndKey = createHwndKey(parentWindowHwnd);
	std::list<std::shared_ptr<Control>> controlList = locateControls(parentWindowHwnd);
	controlList.push_back(control);
	controlRegistry[hwndKey] = controlList;
}
