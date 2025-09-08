#ifndef __STRING__UTILS__H__
#define __STRING__UTILS__H__

#include <string>
#include <sstream>

/**
 * utilities to be used with std::string.
 */
template<typename t> std::string to_std_string(const t &n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str();
}

#endif // __STRING__UTILS__H__
