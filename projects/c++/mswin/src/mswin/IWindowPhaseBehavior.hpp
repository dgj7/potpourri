#ifndef __INTERFACE__WINDOW__PHASE__BEHAVIOR__H__
#define __INTERFACE__WINDOW__PHASE__BEHAVIOR__H__

#include <memory>

class Window;

class IWindowPhaseBehavior
{
protected:
	std::shared_ptr<Window> ptrWindow;
public:
	virtual void execute() = 0;
	
	virtual void setPtrWindow(std::shared_ptr<Window>) = 0;
};

#endif
