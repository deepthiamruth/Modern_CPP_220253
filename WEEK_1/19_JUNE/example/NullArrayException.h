#include<stdexcept>

class NullArrayException
{
private:
    std::string m_msg;
public:

    NullArrayException(std::string msg) : m_msg(msg) {}

    NullArrayException() = default;
    ~NullArrayException() = default;
    NullArrayException(const NullArrayException& other) = default;
    NullArrayException& operator = (const NullArrayException& other) = delete;
    NullArrayException(NullArrayException&& other) = default;
    NullArrayException operator = (NullArrayException&& other) = delete;

    
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return m_msg.c_str(); //return const* to msg string
    }
    ~NullArrayException(){}
};
