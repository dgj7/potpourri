#ifndef __CREATE__WINDOW__EXCEPTION__H__
#define __CREATE__WINDOW__EXCEPTION__H__

#include <stdexcept>
#include <string>

class CreateWindowException : public std::runtime_error
{
public:
	CreateWindowException(std::string);
};

#endif
