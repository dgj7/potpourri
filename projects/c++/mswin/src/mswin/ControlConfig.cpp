#include "ControlConfig.hpp"

ControlConfig::ControlConfig()
{
	//
}

std::string ControlConfig::getWindowClass() const
{
	return windowClass;
}

void ControlConfig::setWindowClass(std::string input)
{
	windowClass = input;
}

std::string ControlConfig::getControlText() const
{
	return controlText;
}

void ControlConfig::setControlText(std::string input)
{
	controlText = input;
}

std::string ControlConfig::getControlName() const
{
	return controlName;
}

void ControlConfig::setControlName(std::string input)
{
	controlName = input;
}

int ControlConfig::getXPos() const
{
	return xPos;
}

void ControlConfig::setXPos(int input)
{
	xPos = input;
}

int ControlConfig::getYPos() const
{
	return yPos;
}

void ControlConfig::setYPos(int input)
{
	yPos = input;
}

int ControlConfig::getWidth() const
{
	return width;
}

void ControlConfig::setWidth(int input)
{
	width = input;
}

int ControlConfig::getHeight() const
{
	return height;
}

void ControlConfig::setHeight(int input)
{
	height = input;
}

DWORD ControlConfig::getDwStyle() const
{
	return dwStyle;
}

void ControlConfig::setDwStyle(DWORD input)
{
	dwStyle = input;
}

DWORD ControlConfig::getDwExStyle() const
{
	return dwExStyle;
}

void ControlConfig::setDwExStyle(DWORD input)
{
	dwExStyle = input;
}
