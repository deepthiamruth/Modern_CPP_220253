#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <iostream>
#include <stdexcept>

class IdNotFoundException : public std::exception
{
private:
    std::string m_msg;
public:
    IdNotFoundException(std::string msg){
        this->m_msg = msg;
    }
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return m_msg.c_str();
    }
    ~IdNotFoundException(){}
};



#endif // IDNOTFOUNDEXCEPTION_H
