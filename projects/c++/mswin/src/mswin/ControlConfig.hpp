#ifndef __CONTROL__CONFIG__H__
#define __CONTROL__CONFIG__H__

#include <string>

#include <windows.h>

class ControlConfig
{
protected:
	std::string windowClass;
	std::string controlText;
	std::string controlName;
	
	int xPos;
	int yPos;
	int width;
	int height;
	
	DWORD dwStyle;
	DWORD dwExStyle;
public:
	ControlConfig();
	
	std::string getWindowClass() const;
	void setWindowClass(std::string);
	
	std::string getControlText() const;
	void setControlText(std::string);
	
	std::string getControlName() const;
	void setControlName(std::string);
	
	int getXPos() const;
	void setXPos(int);
	
	int getYPos() const;
	void setYPos(int);
	
	int getWidth() const;
	void setWidth(int);
	
	int getHeight() const;
	void setHeight(int);
	
	DWORD getDwStyle() const;
	void setDwStyle(DWORD);
	
	DWORD getDwExStyle() const;
	void setDwExStyle(DWORD);
};

#endif
