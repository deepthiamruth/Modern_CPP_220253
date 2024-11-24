#include <iostream>
#include <memory> 


class Data
{
private:
    int m_value{0};
public:
    Data()=default;
    Data(const Data & ) = default; // if we enable we dont get error at Magic(d1);
    Data( Data&& ) = delete;
    Data &  operator = (const Data& ) = delete;
    Data & operator = (Data && ) = delete;
    ~Data()= default;

    // Data(int val ): m_value {val}{
    // }

    explicit Data(int val) :m_value{val}{
    } //explicit constructor cannot be used for auto conversion

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }
};


int main(){
    int32_t x{10};
    char grade {'A'};
    //     int* ptr = (int*) malloc(4);
    //     char* ptr2 = (char*)malloc(1);

    std::unique_ptr <int> ptr1 {(int*) malloc(4)};
    std::unique_ptr <int> ptr2 {new int(x)};
    std::unique_ptr <char> ptr3 {(char*) malloc(1)};
    std:: unique_ptr <Data> ptr4{new Data{100}};
    std:: cout << * ptr1 << "\n" << *ptr2 << "\n" << *ptr3 << "\n" << *ptr4 << "\n" ;
    //dont make l value raw pointers

}

