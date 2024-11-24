
#include <iostream>
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

void Magic(Data d1){
    std:: cout << d1 << "\n";
}

int main(){
    Data d1 {100};
    //Magic(10); //convert int to data uses parameterized constructor   // if we put explicit before param constructor this will not work

    //Magic(d1); // disabled the copy so we get an error .. we can pass by reference

    Magic(Data {100}); // an r value of type data is used to initialize an obj of type data but not copy or moving , compiler simply modifies code as Data d1{100};


}
