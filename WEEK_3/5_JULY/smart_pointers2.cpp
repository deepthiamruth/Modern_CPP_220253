#include <iostream>
#include <memory> 


void Magic(std:: unique_ptr<Data> temp){

}



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
    std::unique_ptr<Data> ptr4 {new Data{100}};

    Magic(std::move(ptr4));

   // ptr4 = new Data{99}; // error because LHS is unique ptr and rhs is diff

    ptr4.reset(new Data{99});




}