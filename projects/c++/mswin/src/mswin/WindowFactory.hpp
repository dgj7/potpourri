#ifndef __WINDOW__FACTORY__H__
#define __WINDOW__FACTORY__H__

#include <memory>

#include <windows.h>

#include "Window.hpp"
#include "Control.hpp"
#include "WindowConfig.hpp"
#include "ControlConfig.hpp"
#include "WindowRegistry.hpp"

#define windowFactory WindowFactory::getInstance()

class Window;
class Control;

class WindowFactory
{
protected:
	static WindowFactory instance;
	WindowFactory();
	
	/* keep track of the number of objects produced, for creation of ids. */
	static int controlsCreated;
	static int windowsCreated;
	
	static void addPhaseBehaviors(WindowConfig,std::shared_ptr<Window>);
public:
	static WindowFactory getInstance();
	
	static std::shared_ptr<Window> createWindow(WindowConfig);
	static std::shared_ptr<Control> createControl(ControlConfig,HWND);
};

#endif
