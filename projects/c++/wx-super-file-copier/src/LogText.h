#ifndef __LOG__TEXT__DG__H__
#define __LOG__TEXT__DG__H__

#include <wx/wx.h>

#include <time.h>

class LogText: public wxLogTextCtrl
{
public:
        LogText( wxTextCtrl *textCtrl );

        void DoLog( int level, wxString message );

protected:
};



#endif
