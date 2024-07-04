
#include <iostream>
class Data
{
private:
    int m_value{0};
public:
    Data()=default;
    Data(const Data & ) = default; // if we enable we dont get error at Magic(d1);
    Data( Data&& ) = default;
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

Data Magic(){
    //return Data {100}; 
    Data obj {100};
    return obj;
}

int main(){
   Data d1 = Magic(); // d1 obj in the main fun is initialized by a return by magic() fun


}
