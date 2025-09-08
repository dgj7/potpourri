#include <iostream>
#include <memory>

#include <windows.h>

#include "mswin/Window.hpp"
#include "mswin/WindowFactory.hpp"
#include "mswin/EventType.hpp"
#include "testapp/WmCloseEventHandler.hpp"
#include "testapp/WmDestroyEventHandler.hpp"
#include "testapp/WmCreateEventHandler.hpp"
#include "mswin/MessageRetrievalStrategy.hpp"
#include "testapp/WmCommandEventHandler.hpp"

WindowConfig createWindowConfig(HINSTANCE,HINSTANCE,int);

EventTypes eventTypes;
MessageRetrievalStrategies msgRetStrats;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	try
	{
		MessageBox(NULL, "beginning of WinMain...", "Status", MB_ICONEXCLAMATION | MB_OK);
		
		WindowConfig winConfig = createWindowConfig(hInstance, hPrevInstance, nCmdShow);
		std::shared_ptr<Window> mainWindow = windowFactory.createWindow(winConfig);
		mainWindow->setMessageRetrievalStrategy(msgRetStrats.UsePeekMessage);
		int ret = mainWindow->loop();
		
		MessageBox(NULL, "end of WinMain!", "Status", MB_ICONEXCLAMATION | MB_OK);
		return ret;
	}
	catch(std::exception &e)
	{
		std::string message(e.what());
		MessageBox(NULL, message.c_str(), "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 1;
	}
	catch(...)
	{
		MessageBox(NULL, "unknown error!", "Error!", MB_ICONEXCLAMATION | MB_OK);
	}
}

WindowConfig createWindowConfig(HINSTANCE hInstance, HINSTANCE hPrevInstance, int nCmdShow)
{
	WindowConfig winConfig;
	
	winConfig.setWindowTitle("TestWindow");
	winConfig.setClassName("TestWindowClassName");
	winConfig.setHInstance(hInstance);
	winConfig.setHPrevInstance(hPrevInstance);
	winConfig.setNCmdShow(nCmdShow);
	winConfig.setWidth(800);
	winConfig.setHeight(600);
	winConfig.setHIcon(LoadIcon(NULL,IDI_APPLICATION));
	winConfig.setHCursor(LoadCursor(NULL,IDC_ARROW));
	winConfig.setHIconSm(LoadIcon(NULL,IDI_APPLICATION));
	winConfig.setHbrBackground((HBRUSH)(COLOR_WINDOW+1));
	winConfig.setDwExStyle(WS_EX_CLIENTEDGE);
	winConfig.setDwStyle(WS_OVERLAPPEDWINDOW);
	winConfig.setXWinPos(CW_USEDEFAULT);
	winConfig.setYWinPos(CW_USEDEFAULT);
	
	winConfig.addEventHandler(eventTypes.EventWmClose, std::make_shared<WmCloseEventHandler>());
	winConfig.addEventHandler(eventTypes.EventWmDestroy, std::make_shared<WmDestroyEventHandler>());
	winConfig.addEventHandler(eventTypes.EventWmCreate, std::make_shared<WmCreateEventHandler>());
	winConfig.addEventHandler(eventTypes.EventWmCommand, std::make_shared<WmCommandEventHandler>());
	
	return winConfig;
}
