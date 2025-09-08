#ifndef __FRAME__DG__H__
#define __FRAME__DG__H__

#include <wx/setup.h>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/dir.h>
#include <time.h>               // for time_t, needed by wxLogTextCtrl

#include "LogText.h"

class Frame: public wxFrame
{
public:
        Frame( const wxString &title );
        ~Frame(  );

        //void copy_thread_completed( wxThreadEvent &);
        //void copy_thread_update( wxThreadEvent & );

        void add_to_file_list( wxString, wxString, wxString );
        void log_append( int, wxString );
private:
        // Events
        DECLARE_EVENT_TABLE()
        void on_quit( wxCommandEvent &event );
        void on_about( wxCommandEvent &event );
        void on_source_button( wxCommandEvent &event );
        void on_target_button( wxCommandEvent &event );
        void on_copy_button( wxCommandEvent &event );
        void on_idle( wxIdleEvent &event );

        // Set up widgets
        void setup_menus(  );
        void setup_source_selector(  );
        void setup_destination_selector(  );
        void setup_options_selector(  );
        void setup_failure_list(  );
        void setup_log_text_control(  );
        void setup_log(  );

        // widgets
        wxMenuBar *menuBar;
        wxMenu *helpMenu;
        wxMenu *fileMenu;
        wxPanel *mainPanel;
        wxButton *sourceButton;
        wxButton *destButton;
        wxButton *copyButton;
        wxTextCtrl *sourceLabel;
        wxTextCtrl *destLabel;
        wxListView *fileList;
        wxTextCtrl *logText;
        wxGauge *copyGauge;
        LogText *log;

        // Sizers
        wxBoxSizer *mainSizer;
        wxBoxSizer *sourceSizer;
        wxStaticBoxSizer *destSizer;
        wxStaticBoxSizer *optionSizer;
        wxStaticBoxSizer *listSizer;
        wxStaticBoxSizer *logSizer;

        // application-related data
        wxString sourceDirectory;
        wxString destinationDirectory;
        wxArrayString allFiles;
        wxDir *source;
        //CopyThread *copyThread;
		//bool threadFinished;

        // State
        bool copying;
};


enum
{
        ID_SOURCE_BUTTON = wxID_HIGHEST,
        ID_TARGET_BUTTON = wxID_HIGHEST - 1,
        ID_COPY_BUTTON = wxID_HIGHEST -2
};

#endif
