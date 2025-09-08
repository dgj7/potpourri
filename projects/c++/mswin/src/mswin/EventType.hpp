#ifndef __EVENT__TYPE__H__
#define __EVENT__TYPE__H__

#include <utility>
#include <string>

#include <windows.h>

class EventType
{
friend class EventTypes;
protected:
    std::pair<int,std::string> type;
    EventType(int,std::string);
public:
    std::string getName() const;
    int getValue() const;
};

class EventTypes
{
public:
	EventType EventWmCreate = EventType(WM_CREATE,"WM_CREATE");
    EventType EventWmClose = EventType(WM_CLOSE,"WM_CLOSE");
	EventType EventWmDestroy = EventType(WM_DESTROY,"WM_DESTROY");
    EventType EventWmKeydown = EventType(WM_KEYDOWN,"WM_KEYDOWN");
    EventType EventWmMousemove = EventType(WM_MOUSEMOVE,"WM_MOUSEMOVE");
    EventType EventWmLButtonDown = EventType(WM_LBUTTONDOWN,"WM_LBUTTONDOWN");
    EventType EventWmRButtonDown = EventType(WM_RBUTTONDOWN,"WM_RBUTTONDOWN");
	EventType EventWmCommand = EventType(WM_COMMAND,"WM_COMMAND");
};

#endif // __EVENT__TYPE__H__
