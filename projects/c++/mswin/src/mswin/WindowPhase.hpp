#ifndef __WINDOW__PHASE__H__
#define __WINDOW__PHASE__H__

#include <utility>
#include <string>

class WindowPhase
{
friend class WindowPhases;
protected:
	std::pair<int,std::string> phase;
	WindowPhase(int,std::string);
public:
	std::string getName() const;
	int getValue() const;
};

class WindowPhases
{
public:
	WindowPhase Constructor = WindowPhase(1,"Constructor");
	WindowPhase BuildPre = WindowPhase(2,"BuildPre");
	WindowPhase BuildPost = WindowPhase(3,"BuildPost");
	WindowPhase Loop = WindowPhase(4,"Loop");
	WindowPhase PeekFailure = WindowPhase(5,"PeekFailure");
	WindowPhase Destructor = WindowPhase(6,"Destructor");
};

#endif
