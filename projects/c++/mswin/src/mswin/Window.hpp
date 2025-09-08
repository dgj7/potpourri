#ifndef __MSW__WINDOW__H__
#define __MSW__WINDOW__H__

#include <memory>
#include <map>
#include <list>

#include <windows.h>

#include "WindowConfig.hpp"
#include "RegistrationException.hpp"
#include "CreateWindowException.hpp"
#include "ErrorMessageConstants.hpp"
#include "EventProcessor.hpp"
#include "Event.hpp"
#include "EventType.hpp"
#include "IWindowPhaseBehavior.hpp"
#include "WindowPhase.hpp"
#include "DefaultWindowPhaseBehavior.hpp"
#include "MessageRetrievalStrategy.hpp"
#include "Control.hpp"
#include "WindowFactory.hpp"
#include "StringUtils.hpp"

class Window
{
friend class WindowFactory;
protected:
	HWND hwnd;
	HDC hdc;
	HGLRC hrc;
	
	WindowConfig winConfig;
	static std::shared_ptr<EventProcessor> eventProcessor;
	std::map<int,std::shared_ptr<IWindowPhaseBehavior>> phaseBehaviors;
	MessageRetrievalStrategy msgRetrievalStrategy;
	
	/* workaround for adding event handlers before the HWND exists (window is created) */
	boolean isHwndKnown = false;
	static std::list<std::pair<EventType,std::shared_ptr<IEventHandler>>> temporaryEventStorage;
	void addQueuedHandlers();
	
	static LRESULT CALLBACK windowProcedure(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
	
	/* construction phase */
	Window(WindowConfig);
	void callConstructionPhaseBehavior();
	void callConstructionHelper();
	
	/* build phase */
	void build();
	void callBuildPrePhaseBehavior();
	void callBuildHelper();
	void callBuildPostPhaseBehavior();
	
	/* loop - peek phase */
	int callLoopHelper();
	void callPeekFailedPhaseBehavior();
	
	/* destruction phase */
	void callDestructionPhaseBehavior();
	void callDestructionHelper();
public:
	int loop();
	virtual ~Window();
	
	HWND getHwnd() const;
	void setMessageRetrievalStrategy(MessageRetrievalStrategy);
	
	HDC getHdc() const;
	void setHdc(HDC);
	HGLRC getHrc() const;
	void setHrc(HGLRC);
	
	void addHandler(EventType,std::shared_ptr<IEventHandler>);
	
	void addBehavior(WindowPhase,std::shared_ptr<IWindowPhaseBehavior>);
	std::shared_ptr<IWindowPhaseBehavior> getBehavior(WindowPhase);
};

#endif
