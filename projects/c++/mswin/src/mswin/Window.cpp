#include "Window.hpp"

std::shared_ptr<EventProcessor> Window::eventProcessor = EventProcessor::getInstance();
std::list<std::pair<EventType,std::shared_ptr<IEventHandler>>> Window::temporaryEventStorage;

WindowPhases windowPhases;
MessageRetrievalStrategies msgRetrievalStrategies;

Window::Window(WindowConfig wc)
:winConfig(wc), msgRetrievalStrategy(msgRetrievalStrategies.UseGetMessage)
{
	callConstructionHelper();
	callConstructionPhaseBehavior();
}

void Window::callConstructionHelper()
{
	/*
	addBehavior(windowPhases.Constructor, std::make_shared<DefaultWindowPhaseBehavior>());
	addBehavior(windowPhases.Build, std::make_shared<DefaultWindowPhaseBehavior>());
	addBehavior(windowPhases.Loop, std::make_shared<DefaultWindowPhaseBehavior>());
	addBehavior(windowPhases.PeekFailure, std::make_shared<DefaultWindowPhaseBehavior>());
	addBehavior(windowPhases.Destructor, std::make_shared<DefaultWindowPhaseBehavior>());
	*/
}

void Window::callConstructionPhaseBehavior()
{
	std::shared_ptr<IWindowPhaseBehavior> behavior = getBehavior(windowPhases.Constructor);
	if(behavior)
		behavior->execute();
}

Window::~Window()
{
	callDestructionPhaseBehavior();
	callDestructionHelper();
}

void Window::callDestructionPhaseBehavior()
{
	std::shared_ptr<IWindowPhaseBehavior> behavior = getBehavior(windowPhases.Destructor);
	if(behavior)
		behavior->execute();
}

void Window::callDestructionHelper()
{
	//
}

HWND Window::getHwnd() const
{
	return hwnd;
}

void Window::build()
{
	callBuildPrePhaseBehavior();
	callBuildHelper();
	callBuildPostPhaseBehavior();
}

void Window::callBuildHelper()
{
	/* create wndcls */
	WNDCLASSEX wc;
	
	wc.cbSize			= sizeof(WNDCLASSEX);
	wc.lpfnWndProc		= Window::windowProcedure;
	wc.style			= winConfig.getStyle();
	wc.cbClsExtra		= winConfig.getCbClsExtra();
	wc.cbWndExtra		= winConfig.getCbWndExtra();
	wc.hInstance		= winConfig.getHInstance();
	wc.hIcon			= winConfig.getHIcon();
	wc.hCursor			= winConfig.getHCursor();
	wc.hbrBackground	= winConfig.getHbrBackground();
	wc.lpszMenuName		= (winConfig.getMenuName().empty() ? NULL : winConfig.getMenuName().c_str());
	wc.lpszClassName	= (winConfig.getClassName().empty() ? NULL : winConfig.getClassName().c_str());
	wc.hIconSm			= winConfig.getHIconSm();
	
	if(!RegisterClassEx(&wc))
	{
		throw RegistrationException(ErrorMessageConstants::WINDOW_REGISTRATION_ERROR_MESSAGE);
	}
	
	HWND tmpHwnd = CreateWindowEx(
		winConfig.getDwExStyle(),
        (winConfig.getClassName().empty() ? NULL : winConfig.getClassName().c_str()),
        (winConfig.getWindowTitle().empty() ? NULL : winConfig.getWindowTitle().c_str()),
        winConfig.getDwStyle(),
        winConfig.getXWinPos(),
		winConfig.getYWinPos(),
		winConfig.getWidth(),
		winConfig.getHeight(),
		winConfig.getHwndParent(),
		winConfig.getHMenu(),
		winConfig.getHInstance(),
		winConfig.getLpParam()
		);
	
	if(tmpHwnd == NULL)
	{
		throw CreateWindowException(ErrorMessageConstants::WINDOW_CREATION_ERROR_MESSAGE);
	}
	
	hwnd = tmpHwnd;
	isHwndKnown = true;
	addQueuedHandlers();
	
	ShowWindow(tmpHwnd, winConfig.getNCmdShow());
	UpdateWindow(tmpHwnd);
}

void Window::callBuildPrePhaseBehavior()
{
	std::shared_ptr<IWindowPhaseBehavior> behavior = getBehavior(windowPhases.BuildPre);
	if(behavior)
		behavior->execute();
}

void Window::callBuildPostPhaseBehavior()
{
	std::shared_ptr<IWindowPhaseBehavior> behavior = getBehavior(windowPhases.BuildPost);
	if(behavior)
		behavior->execute();
}

int Window::loop()
{
	callLoopHelper();
}

int Window::callLoopHelper()
{
	MSG msg;
	
	if(msgRetrievalStrategies.UsePeekMessage.getValue() == msgRetrievalStrategy.getValue())
	{
		/* use peek message */
		while(true)
		{
			while(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			
			if(msg.message == WM_QUIT)
				break;
			
			callPeekFailedPhaseBehavior();
		}
	}
	else if(msgRetrievalStrategies.UseGetMessage.getValue() == msgRetrievalStrategy.getValue())
	{
		/* use get message */
		while(GetMessage(&msg, NULL, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	
	return msg.wParam;
}

void Window::callPeekFailedPhaseBehavior()
{
	std::shared_ptr<IWindowPhaseBehavior> behavior = getBehavior(windowPhases.PeekFailure);
	if(behavior)
		behavior->execute();
}

void Window::addHandler(EventType eventType, std::shared_ptr<IEventHandler> handler)
{
	if(!isHwndKnown)
	{
		std::pair<EventType,std::shared_ptr<IEventHandler>> handlerPair(eventType,handler);
		temporaryEventStorage.push_back(handlerPair);
	}
	else
	{
		std::shared_ptr<WindowEventProcessor> processor = eventProcessor->getProcessor(hwnd);
		
		if(!processor)
		{
			eventProcessor->addProcessor(hwnd, std::make_shared<WindowEventProcessor>());
			processor = eventProcessor->getProcessor(hwnd);
		}
		
		if(processor)
		{
			processor->addHandler(eventType,handler);
		}
	}
}

void Window::addQueuedHandlers()
{
	for(std::pair<EventType,std::shared_ptr<IEventHandler>> tempPair : temporaryEventStorage)
	{
		addHandler(tempPair.first, tempPair.second);
	}
	temporaryEventStorage.clear();
}

LRESULT CALLBACK Window::windowProcedure(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	Event event(hwnd, umsg, wparam, lparam);
	
	if(eventProcessor)
	{
		return eventProcessor->processEvent(event,temporaryEventStorage);
	}
	return DefWindowProc(hwnd, umsg, wparam, lparam);
}

void Window::addBehavior(WindowPhase windowPhase, std::shared_ptr<IWindowPhaseBehavior> behavior)
{
	if(behavior)
	{
		phaseBehaviors[windowPhase.getValue()] = behavior;
	}
}

std::shared_ptr<IWindowPhaseBehavior> Window::getBehavior(WindowPhase windowPhase)
{
	std::map<int,std::shared_ptr<IWindowPhaseBehavior>>::iterator it = phaseBehaviors.find(windowPhase.getValue());
	if(it != phaseBehaviors.end())
		return it->second;
	return nullptr;
}

void Window::setMessageRetrievalStrategy(MessageRetrievalStrategy mrs)
{
	msgRetrievalStrategy = mrs;
}

HDC Window::getHdc() const
{
	return hdc;
}

void Window::setHdc(HDC input)
{
	hdc = input;
}

HGLRC Window::getHrc() const
{
	return hrc;
}

void Window::setHrc(HGLRC input)
{
	hrc = input;
}
