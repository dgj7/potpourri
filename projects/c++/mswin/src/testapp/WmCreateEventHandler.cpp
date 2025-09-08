#include "WmCreateEventHandler.hpp"

int WmCreateEventHandler::handle(Event event)
{
	std::shared_ptr<WindowRegistry> windowRegistry = WindowRegistry::getInstance();
	
	ControlConfig firstButtonConfig = createFirstButtonControlConfig();
	std::shared_ptr<Control> firstButton = windowFactory.createControl(firstButtonConfig, event.getHwnd());
	
	ControlConfig secondButtonConfig = createSecondButtonControlConfig();
	std::shared_ptr<Control> secondButton = windowFactory.createControl(secondButtonConfig, event.getHwnd());
	
	ControlConfig thirdButtonConfig = createThirdButtonControlConfig();
	std::shared_ptr<Control> thirdButton = windowFactory.createControl(thirdButtonConfig, event.getHwnd());
	
	ControlConfig txtConsoleConfig = createConsoleEditBox();
	std::shared_ptr<Control> txtConsole = windowFactory.createControl(txtConsoleConfig, event.getHwnd());
	
	return DefWindowProc(event.getHwnd(), event.getUmsg(), event.getWparam(), event.getLparam());
}

ControlConfig WmCreateEventHandler::createFirstButtonControlConfig()
{
	ControlConfig controlConfig;
	
	controlConfig.setDwExStyle(WS_EX_CLIENTEDGE);
	controlConfig.setWindowClass("BUTTON");
	controlConfig.setControlText("OK");
	controlConfig.setDwStyle(WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON);
	controlConfig.setXPos(10);
	controlConfig.setYPos(10);
	controlConfig.setWidth(100);
	controlConfig.setHeight(50);
	controlConfig.setControlName("btnOk");
	
	return controlConfig;
}

ControlConfig WmCreateEventHandler::createSecondButtonControlConfig()
{
	ControlConfig controlConfig;
	
	controlConfig.setDwExStyle(WS_EX_CLIENTEDGE);
	controlConfig.setWindowClass("BUTTON");
	controlConfig.setControlText("NOT-OK");
	controlConfig.setDwStyle(WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON);
	controlConfig.setXPos(110);
	controlConfig.setYPos(10);
	controlConfig.setWidth(100);
	controlConfig.setHeight(50);
	controlConfig.setControlName("btnNotOk");
	
	return controlConfig;
}

ControlConfig WmCreateEventHandler::createThirdButtonControlConfig()
{
	ControlConfig controlConfig;
	
	controlConfig.setDwExStyle(WS_EX_CLIENTEDGE);
	controlConfig.setWindowClass("BUTTON");
	controlConfig.setControlText("EXIT");
	controlConfig.setDwStyle(WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON);
	controlConfig.setXPos(210);
	controlConfig.setYPos(10);
	controlConfig.setWidth(100);
	controlConfig.setHeight(50);
	controlConfig.setControlName("btnExit");
	
	return controlConfig;
}

ControlConfig WmCreateEventHandler::createConsoleEditBox()
{
	ControlConfig controlConfig;
	
	controlConfig.setDwExStyle(WS_EX_CLIENTEDGE);
	controlConfig.setWindowClass("EDIT");
	controlConfig.setControlText("this is the beginning text in the text\r\ncontrol.");
	controlConfig.setDwStyle(WS_CHILD|WS_VISIBLE|WS_VSCROLL|ES_LEFT|ES_MULTILINE|ES_AUTOVSCROLL);
	controlConfig.setXPos(10);
	controlConfig.setYPos(60);
	controlConfig.setWidth(760);
	controlConfig.setHeight(480);
	controlConfig.setControlName("txtConsole");
	
	return controlConfig;
}
