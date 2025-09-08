#include "Frame.h"
#include <wx/listctrl.h>
#include <wx/thread.h>

#include "DirectoryTraverser.h"
//#include "wx/copy.xpm"

// Event table
//------------------------------------------------------------------------------
BEGIN_EVENT_TABLE(Frame, wxFrame)
        EVT_MENU(wxID_ABOUT, Frame::on_about)
        EVT_MENU(wxID_EXIT, Frame::on_quit)
        EVT_BUTTON(ID_SOURCE_BUTTON, Frame::on_source_button)
        EVT_BUTTON(ID_TARGET_BUTTON, Frame::on_target_button)
        EVT_BUTTON(ID_COPY_BUTTON, Frame::on_copy_button)
        //EVT_COMMAND(wxID_ANY, wxEVT_COMMAND_COPYTHREAD_COMPLETED, Frame::copy_thread_completed)
        //EVT_COMMAND(wxID_ANY, wxEVT_COMMAND_COPYTHREAD_UPDATE, Frame::copy_thread_update)

        EVT_IDLE( Frame::on_idle)
END_EVENT_TABLE()

//wxDEFINE_EVENT(wxEVT_COMMAND_COPYTHREAD_COMPLETED, wxThreadEvent)
//wxDEFINE_EVENT(wxEVT_COMMAND_COPYTHREAD_UPDATE, wxThreadEvent)

Frame::Frame( const wxString &title )
:wxFrame( NULL, wxID_ANY, title )
{
        // Set up variables
        copying = false;                                // Not currently copying any files
        sourceDirectory = wxT( "" );
        destinationDirectory = wxT( "" );
        //copyThread = NULL;

        // Add widgets
        setup_menus(  );                                // Add menus, status bar and icons
        mainPanel = new wxPanel( this, wxID_ANY );      // Main panel for the window
        mainSizer = new wxBoxSizer( wxVERTICAL );       // Configure main sizer
        setup_source_selector(  );                      // Source selection widgets
        setup_destination_selector(  );                 // Destination selection widgets
        setup_options_selector(  );                     // Options selection widgets
        setup_failure_list(  );                         // List control for showing failed copies
        setup_log_text_control(  );                     // Logging text control

        // Set sizer for layout
        mainPanel->SetSizer( mainSizer );               // Use this as sizer
        mainSizer->Fit( this );                         // Fit to min sizes
        mainSizer->SetSizeHints( this );                // Don't get too small

        // Initialize logging
        setup_log(  );                                  // Attach logger to log text control
        log_append( 3, wxT( "Finished creating window." ) );
}

Frame::~Frame(  )
{
        //
}

// Thread functions
//------------------------------------------------------------------------------
/*
void Frame::copy_thread_completed( wxThreadEvent &event )
{

}

void Frame::copy_thread_update( wxThreadEvent &event )
{

}
*/
