#ifndef __REGISTRATION__EXCEPTION__H__
#define __REGISTRATION__EXCEPTION__H__

#include <stdexcept>
#include <string>

class RegistrationException : public std::runtime_error
{
public:
	RegistrationException(std::string);
};

#endif
