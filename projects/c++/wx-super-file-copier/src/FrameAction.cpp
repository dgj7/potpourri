#include "Frame.h"

void Frame::add_to_file_list( wxString fileName, wxString errorText, wxString directoryName )
{
        static long currIndex = 0;

        long index = fileList->InsertItem( 0, fileName );
        fileList->SetItem( index, 1, errorText );
        fileList->SetItem( index, 2, directoryName );
        currIndex++;
}

void Frame::log_append( int level, wxString message )
{
        //message = wxT( "Lv" ) + level + message;
        wxString msg;
        msg << wxT( "Lv" ) << level << wxT( " - " ) << message;
        log->DoLog( level, msg );
}

