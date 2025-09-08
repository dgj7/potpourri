#ifndef __EVENT__H__
#define __EVENT__H__

#include <windows.h>

class Event
{
protected:
	HWND hwnd;
	UINT umsg;
	WPARAM wparam;
	LPARAM lparam;
public:
	Event(HWND, UINT, WPARAM, LPARAM);

	HWND getHwnd() const;
	void setHwnd(HWND);
	
	UINT getUmsg() const;
	void setUmsg(UINT);
	
	WPARAM getWparam() const;
	void setWparam(WPARAM);
	
	LPARAM getLparam() const;
	void setLparam(LPARAM);
};

#endif
