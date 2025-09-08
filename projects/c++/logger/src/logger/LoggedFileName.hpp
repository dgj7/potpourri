#ifndef __LOGGED__FILE__NAME__H__
#define __LOGGED__FILE__NAME__H__

#include <string>

class LoggedFileName
{
protected:
    std::string fileName;
public:
    LoggedFileName(std::string);

    std::string getFileName() const;
    void setFileName(std::string);
};

#endif // __LOGGED__FILE__NAME__H__
