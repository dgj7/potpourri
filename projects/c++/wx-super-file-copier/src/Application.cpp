#include "Application.h"
#include "Frame.h"

IMPLEMENT_APP(Application)

//-----------------------------------------------------------------------------
// Initialization function.
// PURPOSE:  Create window, parse command line parameters, set up
//              data for the application, perform initialization tasks
// RETURN:  boolean.
//              if true, starts the event loop
//              if false, program will terminate
//-----------------------------------------------------------------------------
bool Application::OnInit(  )
{
        // Create the window and make it visible.
        Frame *frame = new Frame( wxT( "Super File Copier" ) );
        frame->Show( true );

        return true;
}
