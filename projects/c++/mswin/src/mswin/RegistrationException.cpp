#include "RegistrationException.hpp"

RegistrationException::RegistrationException(std::string message)
:runtime_error(message)
{
	//
}