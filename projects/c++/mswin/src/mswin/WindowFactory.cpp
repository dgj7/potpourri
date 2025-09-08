#include "WindowFactory.hpp"

WindowFactory WindowFactory::instance;
std::shared_ptr<WindowRegistry> windowRegistry = WindowRegistry::getInstance();
int WindowFactory::controlsCreated = 0;
int WindowFactory::windowsCreated = 0;
WindowPhases windowFactoryWindowPhases;

WindowFactory::WindowFactory()
{
	//
}

WindowFactory WindowFactory::getInstance()
{
	return instance;
}

std::shared_ptr<Window> WindowFactory::createWindow(WindowConfig winConfig)
{
	std::shared_ptr<Window> window = std::shared_ptr<Window>(new Window(winConfig));
	for(std::pair<EventType,std::shared_ptr<IEventHandler>> pairHandler : winConfig.getLstEventHandlers())
	{
		window->addHandler(pairHandler.first, pairHandler.second);
	}
	window->build();
	windowRegistry->addWindow(window);
	
	addPhaseBehaviors(winConfig, window);
	
	/* return */
	windowsCreated++;
	return window;
}

std::shared_ptr<Control> WindowFactory::createControl(ControlConfig ctrlConfig, HWND parentHwnd)
{
	std::shared_ptr<Control> control = std::shared_ptr<Control>(new Control());
	control->build(ctrlConfig,parentHwnd,controlsCreated);
	control->setControlName(ctrlConfig.getControlName());
	controlsCreated++;
	windowRegistry->addControl(control,parentHwnd);
	return control;
}

void WindowFactory::addPhaseBehaviors(WindowConfig winConfig, std::shared_ptr<Window> ptrWin)
{
	/* create default */
	std::shared_ptr<IWindowPhaseBehavior> defaultPhaseBehavior = std::make_shared<DefaultWindowPhaseBehavior>();
	defaultPhaseBehavior->setPtrWindow(ptrWin);
	
	/* constructor behavior */
	std::shared_ptr<IWindowPhaseBehavior> constructor = winConfig.getPhaseBehavior(windowFactoryWindowPhases.Constructor);
	if(!constructor)
	{
		ptrWin->addBehavior(windowFactoryWindowPhases.Constructor, defaultPhaseBehavior);
	}
	else
	{
		constructor->setPtrWindow(ptrWin);
		ptrWin->addBehavior(windowFactoryWindowPhases.Constructor, constructor);
	}
	
	/* build-post behavior */
	std::shared_ptr<IWindowPhaseBehavior> buildPost = winConfig.getPhaseBehavior(windowFactoryWindowPhases.BuildPost);
	if(!buildPost)
	{
		ptrWin->addBehavior(windowFactoryWindowPhases.BuildPost, defaultPhaseBehavior);
	}
	else
	{
		buildPost->setPtrWindow(ptrWin);
		ptrWin->addBehavior(windowFactoryWindowPhases.BuildPost, buildPost);
	}
	
	/* build-pre behavior */
	std::shared_ptr<IWindowPhaseBehavior> buildPre = winConfig.getPhaseBehavior(windowFactoryWindowPhases.BuildPre);
	if(!buildPre)
	{
		ptrWin->addBehavior(windowFactoryWindowPhases.BuildPre, defaultPhaseBehavior);
	}
	else
	{
		buildPre->setPtrWindow(ptrWin);
		ptrWin->addBehavior(windowFactoryWindowPhases.BuildPre, buildPre);
	}
	
	/* loop behavior */
	std::shared_ptr<IWindowPhaseBehavior> loop = winConfig.getPhaseBehavior(windowFactoryWindowPhases.Loop);
	if(!loop)
	{
		ptrWin->addBehavior(windowFactoryWindowPhases.Loop, defaultPhaseBehavior);
	}
	else
	{
		loop->setPtrWindow(ptrWin);
		ptrWin->addBehavior(windowFactoryWindowPhases.Loop, loop);
	}
	
	/* peek behavior */
	std::shared_ptr<IWindowPhaseBehavior> peek = winConfig.getPhaseBehavior(windowFactoryWindowPhases.PeekFailure);
	if(!peek)
	{
		ptrWin->addBehavior(windowFactoryWindowPhases.PeekFailure, defaultPhaseBehavior);
	}
	else
	{
		peek->setPtrWindow(ptrWin);
		ptrWin->addBehavior(windowFactoryWindowPhases.PeekFailure, peek);
	}
	
	/* destructor behavior */
	std::shared_ptr<IWindowPhaseBehavior> destructor = winConfig.getPhaseBehavior(windowFactoryWindowPhases.Destructor);
	if(!destructor)
	{
		ptrWin->addBehavior(windowFactoryWindowPhases.Destructor, defaultPhaseBehavior);
	}
	else
	{
		destructor->setPtrWindow(ptrWin);
		ptrWin->addBehavior(windowFactoryWindowPhases.Destructor, destructor);
	}
}
