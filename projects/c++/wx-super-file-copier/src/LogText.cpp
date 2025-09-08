#include "LogText.h"

LogText::LogText( wxTextCtrl *textCtrl )
:wxLogTextCtrl( textCtrl )
{
        //
}

void LogText::DoLog( int level, wxString message )
{
        time_t now = time( NULL );
        message = wxT( " - " ) + message;
        wxLogTextCtrl::DoLog( level, message, now );
}
