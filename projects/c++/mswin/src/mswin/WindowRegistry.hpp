#ifndef __WINDOW__REGISTRY__H__
#define __WINDOW__REGISTRY__H__

#include <map>
#include <memory>
#include <list>

#include <windows.h>

#include "Window.hpp"
#include "HwndKey.hpp"

class Window;

class WindowRegistry
{
protected:
	std::map<HwndKey,std::shared_ptr<Window>> windowRegistry;
	std::map<HwndKey,std::list<std::shared_ptr<Control>>> controlRegistry;
	static std::shared_ptr<WindowRegistry> instance;
	
	WindowRegistry();
public:
	std::shared_ptr<Window> locateWindow(HWND);
	void addWindow(std::shared_ptr<Window>);
	
	std::list<std::shared_ptr<Control>> locateControls(HWND);
	void addControl(std::shared_ptr<Control>,HWND);
	
	static std::shared_ptr<WindowRegistry> getInstance();
};

#endif
