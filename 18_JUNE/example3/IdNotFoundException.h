#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <stdexcept>
#include<iostream>

class IdNotFoundException: public std:: exception{
    private:
        std:: string message;
    public :
        IdNotFoundException(std:: string _msg){
            this-> message = _msg;
        }
        ~IdNotFoundException(){
            
        }

         virtual const char*
        what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
            return message.c_str();
        }

};

#endif // IDNOTFOUNDEXCEPTION_H
