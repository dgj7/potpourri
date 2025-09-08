// Cal program.
// Designed to be as portable as possible.

// Leap year info:  http://www.timeanddate.com/date/leapyear.html
// Cal manpage:     http://ss64.com/bash/cal.html
// mktime():        http://www.cplusplus.com/reference/clibrary/ctime/mktime/
// localtime():     http://www.cplusplus.com/reference/clibrary/ctime/localtime/

/*
Syntax
      cal [-mjy] [[month] year]

Options:

     -y      Display a calendar for the current year.

    A single parameter specifies the 4 digit year (1 - 9999) to be displayed.

    Two parameters denote the Month (1 - 12) and Year (1 - 9999).

    If arguments are not specified, the current month is displayed.

    A year starts on 01 Jan.
*/

#include <iostream>			// text io
#include <iomanip>			// control of text io presentation
#include <string>			// storage of string data
#include <ctime>            // get current time info
#include <cstdlib>          // atoi()


void print_month( const int m, const int y );
void print_year( const int y );
short calculate_weekday( short d, short m, short y );
short get_current_month(  );
short get_current_year(  );
void print_spaced_header( std::string input, size_t capacity );

int main( int argc, char **argv )
{
	// If no arguments are supplied, print the current month.
	if( argc == 1 )
	{
        // Grab the current year and current month.
        short currentMonth = get_current_month(  );
        short currentYear = get_current_year(  );
		print_month( currentMonth, currentYear );
	}
	else if( argc > 1 || argc < 4 )
	{
	    // If there is only one argument, then either the user is specifying
	    //      -y to print the current year
	    //      or a numerical parameter for the year to print
	    if( argc == 2 )
	    {
	        // First check to see if the -y parameter is used.


	        // If not, treat the input as a year.
            short year = atoi( argv[1] );
            print_year( year );
	    }
	    // If there is two arguments, then the user is specifying
	    // a chosen month and year.  The month may be a numeric value.
	    else if( argc == 3 )
	    {
	        short month = atoi( argv[1] );
	        short year = atoi( argv[2] );
	        print_month( month, year );
	    }
	}
	else
	{
		std::cerr << "Invalid argument count.\n";
		return 1;
	}

	//print_month( 1, 2012 );
	//print_month( 12, 2012 );

	return 0;
}

void print_month( const int m, const int y )
{
	// Lists -- days in each month, weekdays and month names.
	const short daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const std::string dayList[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	const std::string monthList[] = { "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY",
										"JUNE", "JULY", "AUGUST", "SEPTEMBER",
										"OCTOBER", "NOVEMBER", "DECEMBER" };

	// variables.
	short daysCurrentMonth = daysPerMonth[m-1];

	// Print the header
	print_spaced_header( monthList[m-1], 28 );

	for( short x = 0; x < 7; x++ )
		std::cout << dayList[x] << " ";

	// If it's a leap year and it's february, adjust for leap year.
	if( y % 400 == 0 || ( y % 100 != 0 && y % 4 == 0 ) )
		if( m == 2 )
			daysCurrentMonth += 1;

	// Which day is the first day of the month?
	short startDay = calculate_weekday( 1, m, y );

	// Print calendar.
	short ctDays = 0;
	short ctDate = 1;
	while( ctDate <= daysCurrentMonth )
	{
	    // Skip printing the date until you get to the start date for that month.
		if( ctDays < startDay )
		{
			std::cout << std::setw( 4 ) << std::left << "    ";
		}
		else
		{
			std::cout << std::setw( 4 ) << std::left << ctDate;
			ctDate++;
		}

        // Each week, move down to the next line.
		if( ctDays % 7 == 0 )
			std::cout << "\n";

		ctDays++;
	}
}

void print_year( const int y )
{
    std::cout << "            " << y << "            \n";

    for( short m = 1; m < 13; m++ )
    {
        print_month( m, y );
        std::cout << "\n\n";
    }
}

short get_current_year(  )
{
    time_t rawtime;
    struct tm *timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );

    return timeinfo->tm_year + 1900;
}

short get_current_month(  )
{
    time_t rawtime;
    struct tm *timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );

    return timeinfo->tm_mon + 1;
}

void print_spaced_header( std::string input, size_t capacity )
{
    std::string header = "";

    size_t whitespace = capacity - input.size(  ) * 2 - 2;
    whitespace /= 2;
    header += '\n';

    for( size_t a = 0; a < whitespace; a++ )
        header += ' ';

    for( size_t b = 0; b < input.size(  ); b++ )
    {
        header += input[b];
        header += ' ';
    }

    for( size_t a = 0; a < whitespace; a++ )
        header += ' ';

    header += '\n';

    if( header.size(  ) > capacity )
        header = header.substr( 0, capacity );

    std::cout << header;
}

// Calculate the day of the week for a given date.
// IE, March 4 2012 is a Sunday (function returns 1 for Sun).
// Credit: Michael Keith and Tom Craver, Journal of Recreational Mathematics
// http://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
short calculate_weekday( short d, short m, short y )
{
    return ((d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7+1);
}
