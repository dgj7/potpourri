#include "LoggedFileName.hpp"

LoggedFileName::LoggedFileName(std::string fname)
{
    setFileName(fname);
}

std::string LoggedFileName::getFileName() const
{
    return fileName;
}

void LoggedFileName::setFileName(std::string fname)
{
    fileName = fname;
}