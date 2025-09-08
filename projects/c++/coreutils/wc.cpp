/*  wc - recreation of the unix wc program
 *  count the number of times that characters, words, and lines appear in given file(s)
 *
 *  date: november 8, 2013
 *
 *  this program should compile anywhere that standard c++ libraries exist.
 */

#include <iostream>     // std::cout
#include <string>       // std::string
#include <sstream>      // std::stringstream
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <fstream>      // std::ifstream
#include <iomanip>      // std::setw, std::left

#ifndef WC_DEBUG        // print header over output for testing purposes.
#define WC_DEBUG false
#endif

typedef struct FileResults
{
    std::string filename;
    uint64_t charCount;
    uint64_t wordCount;
    uint64_t lineCount;
    uint64_t byteCount;
    uint64_t maxLineCount;
};

void count( FileResults &, std::string whitespace = " \t" );
void print_usage( std::string, std::string );
void print_results( std::vector<FileResults>, bool, bool, bool, bool, bool );
std::string trim_leading_whitespace( std::string, std::string );
std::string get_and_erase_first_token( std::string &, std::string );

int main( int argc, char **argv )
{
    // state
    bool bPrintChar = false;
    bool bPrintWords = false;
    bool bPrintLines = false;
    bool bPrintMaxLines = false;
    bool bShowFilename = true;

    std::vector<FileResults> files;

    // no arguments supplied
    if( argc == 1 )
    {
        print_usage( argv[0], "no arguments supplied." );
        exit( EXIT_FAILURE );
    }
    else if( argc > 1 )
    {
        for( int c = 1; c < argc; c++ )
        {
            std::string arg = argv[c];
            //std::transform( arg.begin(  ), arg.end(  ), arg.begin(  ), ::tolower );

            // if it's an option, figure out what it is and set state accordingly
            if( arg[0] == '-' )
            {
                if( arg[1] != '-' )
                {
                    for( size_t i = 1; i < arg.size(  ); i++ )
                    {
                        if( arg[i] == 'c' )
                        {
                            bPrintChar = true;
                        }
                        else if( arg[i] == 'w' )
                        {
                            bPrintWords = true;
                        }
                        else if( arg[i] == 'l' )
                        {
                            bPrintLines = true;
                        }
                        else if( arg[i] == 'L' )
                        {
                            bPrintMaxLines = true;
                        }
                        else if( arg[i] == 'h' )
                        {
                            bShowFilename = false;
                        }
                        else
                        {
                            print_usage( argv[0], "unknown argument." );
                            exit( EXIT_FAILURE );
                        }
                    }
                }
                else if( arg == "--chars" )
                {
                    bPrintChar = true;
                }
                else if( arg == "--words" )
                {
                    bPrintWords = true;
                }
                else if( arg == "--lines" )
                {
                    bPrintLines = true;
                }
                else if( arg == "--max-line-length" )
                {
                    bPrintMaxLines = true;
                }
                else if( arg == "--hide" )
                {
                    bShowFilename = false;
                }
                else
                {
                    print_usage( argv[0], "incorrect argument supplied" );
                    exit( EXIT_FAILURE );
                }
            }
            else        // if it isnt an option, then its a filename
            {
                FileResults fr;
                fr.filename = arg;
                fr.charCount = 0;
                fr.wordCount = 0;
                fr.lineCount = 0;
                fr.byteCount = 0;
                files.push_back( fr );
            }
        }
    }

    // check the existence of the files before trying to open them all
    for( size_t d = 0; d < files.size(  ); d++ )
    {
        std::ifstream infile;
        infile.open( files[d].filename.c_str(  ) );
        if( !infile.is_open(  ) )
        {
            print_usage( argv[0], "file \"" + files[d].filename + "\" does not exist." );
            exit( EXIT_FAILURE );
        }
        infile.close(  );
    }

    // run the counting function on each file in the list
    for( size_t f = 0; f < files.size(  ); f++ )
    {
        count( files[f] );
    }

    // print the results
    if( files.size(  ) >= 1 )
    {
        // if there's more than one line, add a line for totals
        if( files.size(  ) > 1 )
        {
            FileResults total;
            total.filename = "total";
            total.maxLineCount = 0;
            for( size_t c = 0; c < files.size(  ); c++ )
            {
                total.charCount += files[c].charCount;
                total.byteCount += files[c].byteCount;
                total.lineCount += files[c].lineCount;
                total.wordCount += files[c].wordCount;
                if( files[c].maxLineCount > total.maxLineCount )
                    total.maxLineCount = files[c].maxLineCount;
            }
            files.push_back( total );
        }
        print_results( files, bPrintChar, bPrintWords, bPrintLines, bPrintMaxLines, bShowFilename );
    }
    else
    {
        print_usage( argv[0], "no files specified." );
    }

    return EXIT_SUCCESS;
}

void count( FileResults &fr, std::string whitespace )
{
    std::ifstream file( fr.filename.c_str(  ), std::ios::in );
    size_t maxLineCountTemp = 0;
    if( file.is_open(  ) )
    {
        std::string line = "";
        while( getline( file, line ) )
        {
            // letter and line counts
            fr.charCount += line.size(  );
            fr.lineCount++;

            // max line count
            if( line.size(  ) > maxLineCountTemp )
                maxLineCountTemp = line.size(  );

            // word count
            std::string token = get_and_erase_first_token( line, whitespace );
            while( token != "" )
            {
                fr.wordCount++;
                token = get_and_erase_first_token( line, whitespace );
            }
        }
        fr.maxLineCount = maxLineCountTemp;
    }
    else
    {
        std::cerr << "\ncant open \"" << fr.filename << "\". aborting.";
        file.close(  );
        exit( EXIT_FAILURE );
    }

    // byte count
    std::ifstream inputfile( fr.filename.c_str(  ), std::ios::in | std::ios::binary | std::ios::ate );
    if( inputfile.is_open(  ) )
    {
        fr.byteCount = inputfile.tellg(  );
    }
    else
    {
        std::cerr << "\ncant open \"" << fr.filename << "\". aborting.";
        inputfile.close(  );
        exit( EXIT_FAILURE );
    }
}

void print_usage( std::string binary, std::string message )
{
    std::cout << binary << ":\t" << message
              << "\nusage:\t[-c|-w|-l|-L|-h] [[file] ...]"
              // removed - byte count is now attached to file name in output
              //<< "\n\t-c,--bytes\t\t\tcount and print bytes"
              << "\n\t-c,--chars\t\t\tcount and print characters"
              << "\n\t-w,--words\t\t\tcount and print words"
              << "\n\t-l,--lines\t\t\tcount and print lines"
              << "\n\t-L,--max-line-length\t\tprint the length of the longest line"
              << "\n\t-h,--hide\t\t\thide filename in output"
              << "\n\tfile\t\t\t\tfile(s) to search"
              ;
}

void print_results( std::vector<FileResults> results, bool bPrintChars, bool bPrintWords, bool bPrintLines, bool bPrintMaxLines, bool bShowFilename )
{
    // if they're all false, print them all
    if( !bPrintChars && !bPrintWords && !bPrintLines && !bPrintMaxLines )
    {
        bPrintChars = true;
        bPrintWords = true;
        bPrintLines = true;
    }

    // print header - "debug" testing mode only
    if( WC_DEBUG )
    {
        if( bPrintChars ) std::cout <<      "CHARS     ";
        if( bPrintWords ) std::cout <<      "WORDS     ";
        if( bPrintLines ) std::cout <<      "LINES     ";
        if( bPrintMaxLines ) std::cout <<   "MAX-WIDTH ";
        if( bShowFilename )
        {
            std::cout << "FILENAME                              \n";
        }
    }

    // print one row for each file
    for( size_t c = 0; c < results.size(  ); c++ )
    {
        FileResults res = results[c];

        if( c != 0 ) std::cout << "\n";

        if( bPrintChars )
        {
            std::cout << std::setw( 10 ) << std::left << res.charCount;
        }
        if( bPrintWords )
        {
            std::cout << std::setw( 10 ) << std::left << res.wordCount;
        }
        if( bPrintLines )
        {
            std::cout << std::setw( 10 ) << std::left << res.lineCount;
        }
        if( bPrintMaxLines )
        {
            std::cout << std::setw( 10 ) << std::left << res.maxLineCount;
        }

        if( bShowFilename )
        {
            std::string fname = res.filename;
            std::stringstream ss;
            ss << res.byteCount;
            fname += " (" + ss.str(  ) + " bytes)";
            if( fname.size(  ) > 40 )
            {
                size_t start = (fname.size(  ) - 40) + 4;
                fname = "..." + fname.substr( start, fname.size(  ) - 1 );
            }
            std::cout << std::setw( 39 ) << std::left << fname;
        }
    }
}

std::string trim_leading_whitespace( std::string input, std::string ws )
{
	size_t location = input.find_first_of( ws );
	while( location == 0 )
	{
		input.erase( 0, 1 );
		location = input.find_first_of( ws );
	}

	return input;
}

std::string get_and_erase_first_token( std::string &input, std::string delim )
{
	std::string retstr = "";
	input = trim_leading_whitespace( input, delim );

	if( input.empty(  ) || delim.empty(  ) )
	{
		return retstr;
	}

	size_t loc = input.find_first_of( delim );

	if( loc == std::string::npos )
	{
		retstr = input;
		input = "";
		return retstr;
	}
	else
	{
		retstr = input.substr( 0, loc );
		input.erase( 0, loc );
		return retstr;
	}
}
