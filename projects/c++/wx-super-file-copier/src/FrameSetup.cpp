#include "Frame.h"

void Frame::setup_menus(  )
{
        fileMenu = new wxMenu;

        helpMenu = new wxMenu;
        helpMenu->Append( wxID_ABOUT, wxT( "&About...\tF1" ), wxT( "Show about dialog" ) );

        fileMenu->Append( wxID_EXIT, wxT( "E&xit\tAlt-X" ), wxT( "Quit the program" ) );

        menuBar = new wxMenuBar(  );
        menuBar->Append( fileMenu, wxT( "&File" ) );
        menuBar->Append( helpMenu, wxT( "&Help" ) );

        SetMenuBar( menuBar );

        CreateStatusBar( 2 );                                                                   // Add status bar
        SetStatusText( wxT( "Ready." ) );
        SetStatusText( wxT( "********" ), 1 );

        //SetIcon( wxIcon( copy_xpm ) );                                                        // Add an icon
}

void Frame::setup_source_selector(  )
{
        sourceSizer = new wxStaticBoxSizer( wxHORIZONTAL, mainPanel, wxT( "Source" ) );
        sourceButton = new wxButton( mainPanel, ID_SOURCE_BUTTON, wxT( "Browse..." ) );
        sourceLabel = new wxTextCtrl( mainPanel, wxID_ANY, wxT( "<sauce here>" ), wxDefaultPosition, wxSize( 480, -1 ), wxTE_READONLY );
        sourceSizer->Add( sourceButton, 0, wxALL, 5 );
        sourceSizer->Add( sourceLabel, 5, wxALL, 5 );
        mainSizer->Add( sourceSizer, 0, wxALIGN_LEFT | wxEXPAND );
}

void Frame::setup_destination_selector(  )
{
        destSizer = new wxStaticBoxSizer( wxHORIZONTAL, mainPanel, wxT( "Destination" ) );
        destButton = new wxButton( mainPanel, ID_TARGET_BUTTON, wxT( "Browse..." ) );
        destLabel = new wxTextCtrl( mainPanel, wxID_ANY, wxT( "<target here>" ), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
        destLabel->SetDefaultStyle( wxTextAttr( *wxBLUE, *wxLIGHT_GREY ) );
        destSizer->Add( destButton, 0, wxALL, 5 );
        destSizer->Add( destLabel, 5, wxALL, 5 );
        mainSizer->Add( destSizer, 0, wxALIGN_LEFT | wxEXPAND );
}

void Frame::setup_options_selector(  )
{
        optionSizer = new wxStaticBoxSizer( wxHORIZONTAL, mainPanel, wxT( "Options" ) );
        copyButton = new wxButton( mainPanel, ID_COPY_BUTTON, wxT( "&Copy" ) );
        optionSizer->Add( copyButton, 1, wxALL, 5 );
        mainSizer->Add( optionSizer, 0, wxEXPAND, 5 );

        // add wxGauge here
        /*
        copyGauge
        */
}

void Frame::setup_failure_list(  )
{
        listSizer = new wxStaticBoxSizer( wxHORIZONTAL, mainPanel, wxT( "Errors" ) );
        fileList = new wxListView( mainPanel, wxID_ANY, wxDefaultPosition, wxSize( -1, 100 ), wxLC_REPORT | wxLC_ALIGN_LEFT | wxLC_SINGLE_SEL | wxLC_HRULES | wxLC_VRULES );
        listSizer->Add( fileList, 1, wxEXPAND, 5 );
        mainSizer->Add( listSizer, 1, wxEXPAND, 5 );
        fileList->InsertColumn( 0, wxT( "Filename" ), wxLIST_FORMAT_LEFT, 200 );
        fileList->InsertColumn( 1, wxT( "Error" ), wxLIST_FORMAT_LEFT, 200 );
        fileList->InsertColumn( 2, wxT( "Path" ), wxLIST_FORMAT_LEFT, 1000 );
}

void Frame::setup_log_text_control(  )
{
        logSizer = new wxStaticBoxSizer( wxHORIZONTAL, mainPanel, wxT( "Log" ) );
        logText = new wxTextCtrl( mainPanel, wxID_ANY, wxT( "" ), wxDefaultPosition, wxSize( -1, 150 ), wxTE_READONLY | wxTE_MULTILINE );
        logSizer->Add( logText, 1, wxALL, 5 );
        mainSizer->Add( logSizer, 0, wxEXPAND, 5 );
}

void Frame::setup_log(  )
{
        //log = new wxLogTextCtrl( logText );
        log = new LogText( logText );
        log->SetLogLevel( 3 );                  // Show logs of level 3 and lower
        log->SetActiveTarget( log );
}
