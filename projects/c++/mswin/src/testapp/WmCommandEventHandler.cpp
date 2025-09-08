#include "WmCommandEventHandler.hpp"

int WmCommandEventHandler::handle(Event event)
{
	std::shared_ptr<WindowRegistry> windowRegistry = WindowRegistry::getInstance();
	std::list<std::shared_ptr<Control>> lstControls = windowRegistry->locateControls(event.getHwnd());
	std::string controlName = "UNKNOWN";
	std::string controlIdList = "";
	for(std::shared_ptr<Control> control : lstControls)
	{
		if(LOWORD(event.getWparam()) == control->getControlId())
			controlName = control->getControlName();
		
		controlIdList = controlIdList + ", ";
		controlIdList = controlIdList + to_std_string(control->getControlId());
	}
	
	std::string message = "handling WM_COMMAND...";
	message = message + "\ncontrols with this hwnd: [";
	message = message + to_std_string(lstControls.size());
	message = message + "].";
	message = message + "\ncontrol ids: [";
	message = message + controlIdList;
	message = message + "].";
	message = message + "\nthis control's \"name\": [";
	message = message + controlName;
	message = message + "].";
	
	MessageBox(NULL,message.c_str(),"Status",MB_ICONEXCLAMATION|MB_OK);
	return 0;
}
