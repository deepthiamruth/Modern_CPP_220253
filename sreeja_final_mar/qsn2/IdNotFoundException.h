#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <exception>
#include <iostream>

class IdNotFoundException : public std::exception
{
private:
    std::string m_msg {""};
public:
    IdNotFoundException() = default;
    ~IdNotFoundException() = default;
    IdNotFoundException(std::string msg) : m_msg{msg} {}
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return m_msg.c_str();
    }
};



#endif // IDNOTFOUNDEXCEPTION_H
