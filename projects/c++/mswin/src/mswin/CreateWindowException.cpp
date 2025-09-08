#include "CreateWindowException.hpp"

CreateWindowException::CreateWindowException(std::string message)
:runtime_error(message)
{
	//
}
