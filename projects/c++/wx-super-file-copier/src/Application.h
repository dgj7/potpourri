#ifndef __APPLICATION__DG__H__
#define __APPLICATION__DG__H__

#include <wx/wx.h>

class Application: public wxApp
{
public:
        virtual bool OnInit(  );
};

DECLARE_APP(Application)

#endif
