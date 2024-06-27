#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include <stdexcept>
class NullPointerException:public std::exception
{
private:
    std::string _msg;
public:
    NullPointerException(std::string msg) {
        this->_msg=msg;
    }
    ~NullPointerException() {}
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
    }

};

#endif // NULLPOINTEREXCEPTION_H
