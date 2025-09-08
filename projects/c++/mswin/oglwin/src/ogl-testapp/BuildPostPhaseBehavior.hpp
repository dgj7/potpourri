#ifndef __BUILD__POST__PHASE__BEHAVIOR__H__
#define __BUILD__POST__PHASE__BEHAVIOR__H__

#include <memory>

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
//#include <gl\glaux.h>

#include "../mswin/IWindowPhaseBehavior.hpp"
#include "../mswin/WindowConfig.hpp"
#include "../mswin/Window.hpp"

class BuildPostPhaseBehavior : public IWindowPhaseBehavior
{
protected:
	WindowConfig winConfig;
public:
	BuildPostPhaseBehavior(WindowConfig);

	virtual void execute();
	virtual void setPtrWindow(std::shared_ptr<Window>);
};

#endif
