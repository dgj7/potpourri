#include "Frame.h"

#include <wx/string.h>
#include <wx/filename.h>

#include <exception>

// Idle event handler -- copy files one at a time whenever idle
void Frame::on_idle( wxIdleEvent &event )
{
        // Re-enable the copy button if copying has finished
        if( !copying )
        {
                copyButton->Enable( true );
                copyButton->SetLabel( wxT( "&Copy" ) );
        }

        // Request more idle processing time
        event.RequestMore(  );

        // Print iterations in the log, to see how often this executes
        //static long count = 0;
        //wxString message;
        //message << wxT( "Iteration " ) << count;
        //count++;
        //log_append( 3, message );
}

void Frame::on_source_button( wxCommandEvent &event )
{
        sourceButton->Enable( false );

        wxDirDialog sourcePicker( mainPanel, wxT( "Choose source..." ), wxGetCwd(  ), wxDD_DEFAULT_STYLE );
        if( sourcePicker.ShowModal(  ) == wxID_OK )
        {
                sourceDirectory = sourcePicker.GetPath(  );
                sourceLabel->SetLabel( sourceDirectory );
                log_append( 3, wxT( "Successfully chose source directory." ) );
        }
        else
        {
                log_append( 3, wxT( "Declined to choose source directory." ) );
        }

        sourceButton->Enable( true );
}

void Frame::on_target_button( wxCommandEvent &event )
{
        destButton->Enable( false );

        wxDirDialog destinationPicker( mainPanel, wxT( "Choose destination..." ), wxGetCwd(  ), wxDD_DEFAULT_STYLE );
        if( destinationPicker.ShowModal(  ) == wxID_OK )
        {
                destinationDirectory = destinationPicker.GetPath(  );
                destLabel->SetLabel( destinationDirectory );
                log_append( 3, wxT( "Successfully chose destination directory." ) );
        }
        else
        {
                log_append( 3, wxT( "Declined to choose destination directory." ) );
        }

        destButton->Enable( true );
}

void Frame::on_copy_button( wxCommandEvent &event )
{
        if( sourceDirectory == wxT( "" ) || destinationDirectory == wxT( "" ) )
        {
                log_append( 2, wxT( "You need to choose both source and destination directory before copying!" ) );
                return;
        }
        //log_append( 3, wxT( "Begin copy button handler..." ) );

		// Disable copy button until process completes.
        copyButton->Enable( false );
        copyButton->SetLabel( wxT( "Copying...." ) );
        copying = true;

        // example -- getting the listctrl to work!
        static long currIndex = 0;
        wxString c1, c2, c3;
        c1 << wxT( "Column 1, message " ) << currIndex;
        c2 << wxT( "Column 2, message " ) << currIndex;
        c3 << wxT( "Column 3, message " ) << currIndex;
        this->add_to_file_list( c1, c2, c3 );
        currIndex++;

        // Get source directory info and list all files there
        source = new wxDir( sourceDirectory );
        if( !source->IsOpened(  ) )
        {
                log_append( 1, wxT( "Failed to open source directory." ) );
                //log_append( 3, wxT( "End copy button handler." ) );

                copying = false;
                copyButton->Enable( true );
                copyButton->SetLabel( wxT( "Copy" ) );
                //log_append( 3, wxT( "End copy button handler." ) );

                return;
        }
        else
        {
                //log_append( 3, wxT( "Successfully opened source dir, grabbing list of files..." ) );

                try
                {
                    wxArrayString filelist;
                    size_t fileCount = wxDir::GetAllFiles( sourceDirectory, &filelist );

                    if( fileCount > 0 )
                    {
                        //Create a directory with the same name as the source directory.
                        //wxString baseDir = destinationDirectory + '\\' + sourceDirectory.AfterLast( '\\' );
                        //log_append( 3, wxT( "Creating new directory " ) + baseDir );

                        // For each file in the list, copy it to the specified target directory.
                        for( size_t c = 0; c < filelist.GetCount(  ); c++ )
                        {
                            // Generate the final destination string.
                            wxString finalDestination = destinationDirectory
                                                    + wxT( '\\' )
                                                    + sourceDirectory.AfterLast( '\\' )
                                                    + filelist[c].substr( sourceDirectory.size(  ), filelist[c].size(  ) - 1 );

                            //log_append( 3, wxT( "Source:            " ) + filelist[c] );
                            //log_append( 3, wxT( "Final destination: " ) + finalDestination );
                            log_append( 3, wxT( "Copying " ) + filelist[c] + wxT( "..." ) );

                            // Create the target directory structure, if needed.
                            wxString volume;
                            wxString path;
                            wxString destTemp = finalDestination;
                            wxFileName::SplitPath( destTemp, &volume, &path, NULL, NULL );
                            if( wxDirExists( volume + wxT( ":" ) + wxT( '\\' ) + path ) )
                            {
                                // Perform file copy.
                                if( !wxCopyFile( filelist[c], finalDestination ) )
                                {
                                    // If file copy fails, add to the error report.
                                    this->add_to_file_list( filelist[c], wxT( "" ), wxT( "" ) );
                                    //log_append( 2, wxT( "Failed to copy " ) + filelist[c] );
                                }
                            }
                            else
                            {
                                if( wxFileName::Mkdir( volume + wxT( ":" ) + wxT( '\\' ) + path ), 0777, wxPATH_MKDIR_FULL );
                                {
                                    // Perform file copy.
                                    if( !wxCopyFile( filelist[c], finalDestination ) )
                                    {
                                        // If file copy fails, add to the error report.
                                        this->add_to_file_list( filelist[c], wxT( "" ), wxT( "" ) );
                                        //log_append( 2, wxT( "Failed to copy " ) + filelist[c] );
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        log_append( 3, wxT( "No files to copy." ) );
                    }

                    // Done copying.
                    copying = false;
                    copyButton->Enable( true );
                    copyButton->SetLabel( wxT( "Copy" ) );
                    log_append( 3, wxT( "End copy button handler." ) );
                }
                catch( std::exception &e )
                {

                }
                catch( ... )
                {

                }
        }
}

void Frame::on_about( wxCommandEvent &event )
{
        //
}

void Frame::on_quit( wxCommandEvent &event )
{
        Close(  );
}
