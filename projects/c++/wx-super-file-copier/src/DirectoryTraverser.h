#ifndef __DIRECTORY__TRAVERSER__DG__H__
#define __DIRECTORY__TRAVERSER__DG__H__

#include <wx/wx.h>
#include <wx/dir.h>
#include <wx/filename.h>

class DirTrav: public wxDirTraverser
{
public:
        DirTrav( wxArrayString &files ) : mSourceDir( files )
        {
                dirCount = 0;
                filCount = 0;
        }

        virtual wxDirTraverseResult OnFile( const wxString &filename )
        {
                //std::cout << "\nFound file -- " << filename;
                filCount++;
                mSourceDir.Add( filename );
                return wxDIR_CONTINUE;
        }

        virtual wxDirTraverseResult OnDir( const wxString &dirname )
        {
                //std::cout << "\nFound dir  -- " << dirname;
                dirCount++;
                return wxDIR_CONTINUE;
        }

        wxString print_info(  )
        {
                wxString output = wxT( "" );
                output << wxT( "\n\t=====SOURCE DIRECTORY INFORMATION=====\n" )
                        << wxT( "\n\tFiles:\t" ) << filCount
                        << wxT( "\n\tDirec:\t" ) << dirCount;
                for( size_t c = 0; c < mSourceDir.GetCount(  ); c++ )
                {
                        output << wxT( "\n\t" ) << mSourceDir[c];
                }
                output << wxT( "\n" );
                return output;
        }

        wxString get_next_file_path(  )
        {
                static size_t count = 0;

                return mSourceDir[count];
                count++;
        }
private:
        wxArrayString mSourceDir;
        long dirCount;
        long filCount;
};




#endif
