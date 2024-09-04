#ifndef EmptyDataException_H
#define EmptyDataException_H

#include <exception>
#include <iostream>

class EmptyDataException : public std::exception
{
private:
    std::string m_msg {""};
public:
    EmptyDataException() = default;
    ~EmptyDataException() = default;
    EmptyDataException(std::string msg) : m_msg{msg} {}
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return m_msg.c_str();
    }
};



#endif // EmptyDataException_H
