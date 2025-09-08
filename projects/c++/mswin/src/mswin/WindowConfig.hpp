#ifndef __WINDOW__CONFIG__H__
#define __WINDOW__CONFIG__H__

#include <string>
#include <utility>
#include <list>
#include <memory>
#include <map>

#include <windows.h>

#include "EventType.hpp"
#include "IEventHandler.hpp"
#include "IWindowPhaseBehavior.hpp"
#include "WindowPhase.hpp"

class WindowConfig
{
protected:
	int nCmdShow;
	int width;
	int height;
	int cbClsExtra;
	int cbWndExtra;
	int xWinPos;
	int yWinPos;
	
	std::string windowTitle;
	std::string className;
	std::string menuName;
	
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	UINT cbSize;
	UINT style;
	HICON hIcon;
	HICON hIconSm;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	DWORD dwExStyle;
	DWORD dwStyle;
	HWND hwndParent;
	HMENU hMenu;
	LPVOID lpParam;
	
	boolean fullscreen;
	
	std::list<std::pair<EventType,std::shared_ptr<IEventHandler>>> lstEventHandlers;
	std::map<int,std::shared_ptr<IWindowPhaseBehavior>> phaseBehaviors;
public:
	WindowConfig();
	
	HINSTANCE getHInstance() const;
	void setHInstance(HINSTANCE);
	
	HINSTANCE getHPrevInstance() const;
	void setHPrevInstance(HINSTANCE);
	
	std::string getWindowTitle() const;
	void setWindowTitle(std::string);
	
	int getNCmdShow() const;
	void setNCmdShow(int);
	
	int getWidth() const;
	void setWidth(int);
	
	int getHeight() const;
	void setHeight(int);
	
	std::string getClassName() const;
	void setClassName(std::string);
	
	std::string getMenuName() const;
	void setMenuName(std::string);
	
	UINT getCbSize() const;
	void setCbSize(UINT);
	
	UINT getStyle() const;
	void setStyle(UINT);
	
	int getCbClsExtra() const;
	void setCbClsExtra(int);
	
	int getCbWndExtra() const;
	void setCbWndExtra(int);
	
	HICON getHIcon() const;
	void setHIcon(HICON);
	
	HICON getHIconSm() const;
	void setHIconSm(HICON);
	
	HCURSOR getHCursor() const;
	void setHCursor(HCURSOR);
	
	HBRUSH getHbrBackground() const;
	void setHbrBackground(HBRUSH);
	
	DWORD getDwExStyle() const;
	void setDwExStyle(DWORD);
	
	DWORD getDwStyle() const;
	void setDwStyle(DWORD);
	
	int getXWinPos() const;
	void setXWinPos(int);
	
	int getYWinPos() const;
	void setYWinPos(int);
	
	HWND getHwndParent() const;
	void setHwndParent(HWND);
	
	HMENU getHMenu() const;
	void setHMenu(HMENU);
	
	LPVOID getLpParam() const;
	void setLpParam(LPVOID);
	
	bool isFullscreen() const;
	void setFullscreen(bool);
	
	std::list<std::pair<EventType,std::shared_ptr<IEventHandler>>> getLstEventHandlers() const;
	void addEventHandler(EventType,std::shared_ptr<IEventHandler>);
	
	std::shared_ptr<IWindowPhaseBehavior> getPhaseBehavior(WindowPhase);
	void addPhaseBehavior(WindowPhase, std::shared_ptr<IWindowPhaseBehavior>);
};

#endif
