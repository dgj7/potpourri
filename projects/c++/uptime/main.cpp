#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    DWORD uptime = GetTickCount(  );
    std::cout << uptime << "\n"; 
    const DWORD ms_per_second = 1000;
    const DWORD ms_per_minute = ms_per_second * 60;
    const DWORD ms_per_hour = ms_per_minute * 60;
    const DWORD ms_per_day = ms_per_hour * 24;
    
    int day = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    int millisecond = 0;
    
    // Get days
    if( uptime >= ms_per_day )
    {
        day = uptime / ms_per_day;
        uptime -= day * ms_per_day;
    }
    
    if( uptime >= ms_per_hour )
    {
        hour = uptime / ms_per_hour;
        uptime -= hour * ms_per_hour;
    }
    
    if( uptime >= ms_per_minute )
    {
        minute = uptime / ms_per_minute;
        uptime -= minute * ms_per_minute;
    }
    
    if( uptime >= ms_per_second )
    {
        second = uptime / ms_per_second;
        uptime -= second * ms_per_second;
    }
    
    millisecond = uptime;
    
    
    

    
    // Print results
    std::cout << day << "d, " << hour << "h, " << minute << "m, " << second 
              << "." << millisecond << "s\n";

    return 0;
}
