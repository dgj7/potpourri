#ifndef __COPY__THREAD__DG__H__
#define __COPY__THREAD__DG__H__

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/vector.h>
#include <wx/string.h>

class CopyThread: public wxThread
{
public:
        CopyThread(  );
        ~CopyThread(  );

        bool copy_file( wxString &source, wxString &destination );
        wxThreadError Run(  );

		//void setup( wxVector<wxString>, bool & );

        // Do NOT call Entry directly -- instead call Run()
        virtual void *Entry();
private:
	//bool *_threadFinished;
	wxVector<wxString> _filelist;
};


#endif
