#include "Event.hpp"

Event::Event(HWND h, UINT u, WPARAM w, LPARAM l)
:hwnd(h), umsg(u), wparam(w), lparam(l)
{
	//
}

HWND Event::getHwnd() const
{
	return hwnd;
}

void Event::setHwnd(HWND h)
{
	hwnd = h;
}

UINT Event::getUmsg() const
{
	return umsg;
}

void Event::setUmsg(UINT u)
{
	umsg = u;
}

WPARAM Event::getWparam() const
{
	return wparam;
}

void Event::setWparam(WPARAM w)
{
	wparam = w;
}

LPARAM Event::getLparam() const
{
	return lparam;
}

void Event::setLparam(LPARAM l)
{
	lparam = l;
}
