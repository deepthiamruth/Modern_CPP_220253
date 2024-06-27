#include <iostream>
#include <vector>

enum class Rating {
    _5_STAR,
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    NO_RATING
};

class Car
{
private:
    unsigned int m_id {0};
    float m_price {0.0f};
    Rating m_safetyRating {Rating::NO_RATING};
public:

    Car(unsigned int id) : m_id{id} {}

    Car(unsigned int id, float price) : Car(id) {
        m_price = price;
    }
    // Car(unsigned int id, float price) : m_id {id}, m_price {price} {

    // }

    //This leads to copying or duplicating the data from previous constructor. We can avoid this using Constructor Delegation
    // Car(unsigned int id, float price, Rating rating) : m_id {id}, m_price {price}, m_safetyRating {rating} {

    // }

    //Constructor delegation : In the below lines of code we are redirecting the 2 parameters to be picked from the previous constructor
    Car(unsigned int id, float price, Rating rating)
    :Car(id, price) { 
        m_safetyRating = rating;
      }


    Car() = delete;
    Car(const Car&) =default;
    Car& operator = (const Car&) = delete;
    Car& operator = (Car&&) = delete;
    Car(Car&&) = delete;
    ~Car() = default;
};

int main() {
    // Car c1(101, 1999.9f, Rating::_4_STAR);
    // Car c2(102, 2999.9f, Rating::_3_STAR);

    //std::vector<Car> cars {c1, c2}; // This will throw error so option1: copy ctor is disabled so enable it 
    //Option2: ther way to resolve it would be a move option but that would'nt work
    //Option3: Create data inside the vector directly (emplacing)
    
    //emplacing is applicable only when we use modern cpp
    std::vector<Car>cars;
    cars.emplace_back(101, 1000.0f, Rating::_4_STAR);
    cars.emplace_back(102, 2999.9f, Rating::_3_STAR);
    std::cout << "Number of elements are : " << cars.size() << "\n";
   
    //If we specify the size then it can be used on any platform with the same specific size/memory
    // int32_t n1 = 10; //32 bit/4 bytes for integer
    // int16_t n1 = 20; //16bits/2bytes memory
}