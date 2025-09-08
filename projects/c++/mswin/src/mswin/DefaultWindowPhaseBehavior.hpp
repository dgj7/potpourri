#ifndef __DEFAULT__WINDOW__PHASE__BEHAVIOR__H__
#define __DEFAULT__WINDOW__PHASE__BEHAVIOR__H__

#include "IWindowPhaseBehavior.hpp"

class DefaultWindowPhaseBehavior : public IWindowPhaseBehavior
{
public:
	virtual void execute();
	virtual void setPtrWindow(std::shared_ptr<Window>);
};

#endif
