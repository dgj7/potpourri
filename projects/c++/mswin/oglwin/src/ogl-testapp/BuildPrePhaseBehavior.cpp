#include "BuildPrePhaseBehavior.hpp"

BuildPrePhaseBehavior::BuildPrePhaseBehavior(WindowConfig input)
: winConfig(input)
{
	//
}

void BuildPrePhaseBehavior::execute()
{
	int bits = 16;
	
	if(winConfig.isFullscreen())
	{
		// Try to use fullscreen mode, with the below settings.
		DEVMODE dmScreenSettings;					// Device mode
		memset( &dmScreenSettings, 0, sizeof( dmScreenSettings ) );	//clear mem
		dmScreenSettings.dmSize = sizeof( dmScreenSettings );	//sz of dm strc
		dmScreenSettings.dmPelsWidth = winConfig.getWidth();
		dmScreenSettings.dmPelsHeight = winConfig.getHeight();
		dmScreenSettings.dmBitsPerPel = bits;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try to set selected mode and get results.
		// If fail, allow user to choose to use regular window, or exit program
		// NOTE: CDS_FULLSCREEN gets rid of start bar.
		if( ChangeDisplaySettings( &dmScreenSettings, CDS_FULLSCREEN ) != DISP_CHANGE_SUCCESSFUL )
		{
			if( MessageBox( NULL, "full screen is not available!", winConfig.getClassName().c_str(), MB_YESNO | MB_ICONEXCLAMATION ) == IDYES )
			{
				//fullscreen = false;
			}
			else
			{
				MessageBox( NULL, "Program closing.","ERROR", MB_OK | MB_ICONSTOP );
				//return false;
			}
		}
	}
}

void BuildPrePhaseBehavior::setPtrWindow(std::shared_ptr<Window> winPtr)
{
	ptrWindow = winPtr;
}
