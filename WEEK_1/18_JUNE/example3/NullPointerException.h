#include <iostream>
#include <stdexcept>
class NullPointerException
{
private:
    std:: string message;
public:
    NullPointerException(std::string _msg) : message{_msg}{}
    ~NullPointerException() {}

         virtual const char*
        what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
            return message.c_str();
        }

};