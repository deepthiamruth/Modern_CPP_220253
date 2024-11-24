#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <stdexcept>
class IDNotFoundException:public std::exception
{
private:
    std::string _msg;
public:
    IDNotFoundException(std::string msg) {
        this->_msg=msg;
    }
    ~IDNotFoundException() {}

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
    }
};

#endif // IDNOTFOUNDEXCEPTION_H
