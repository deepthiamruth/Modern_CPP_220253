#ifndef NoMatchingInstance_H
#define NoMatchingInstance_H

#include <exception>
#include <iostream>

class NoMatchingInstance : public std::exception
{
private:
    std::string m_msg {""};
public:
    NoMatchingInstance() = default;
    ~NoMatchingInstance() = default;
    NoMatchingInstance(std::string msg) : m_msg{msg} {}
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return m_msg.c_str();
    }
};



#endif // NoMatchingInstance_H
