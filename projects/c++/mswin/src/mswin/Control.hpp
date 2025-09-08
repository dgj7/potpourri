#ifndef __CONTROL__H__
#define __CONTROL__H__

#include <string>

#include <windows.h>

#include "ControlConfig.hpp"
#include "ErrorMessageConstants.hpp"
#include "CreateWindowException.hpp"

class Control
{
friend class WindowFactory;
protected:
	HWND hwnd;
	int controlId;
	std::string controlName;
	
	/* construction phase */
	Control();
	
	/* build phase */
	void build(ControlConfig,HWND,int);
public:
	HWND getHwnd() const;
	
	std::string getControlName() const;
	void setControlName(std::string);
	
	int getControlId() const;
};

#endif
