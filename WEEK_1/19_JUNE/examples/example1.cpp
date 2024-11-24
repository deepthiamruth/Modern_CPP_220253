#include<iostream>
enum class Rating{
    _5_STAR,
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    _NO_RATING
};

class Car{
    private:
        unsigned int m_id{0};
        float m_price{0.0f};
        Rating m_safetyrating {Rating:: _5_STAR};
    public:
        // Combining two construtors together (CONSTRUCTION DELICATION)
        Car(unsigned int id) : m_id{id}{}
        Car(unsigned int id, float price ): Car (id){
            m_price = price;
        }
        Car(unsigned int id, float price, Rating rating): Car(id,price) { m_safetyrating = rating;}

        Car() = delete;
        Car(const Car&)= delete;
        Car& operator= (const Car& )= delete;
        Car& operator = (Car&&) = delete;
        Car(Car&&) = delete;
        ~Car() = default;
};

int main(){
    Car c1(101, 1000.0f , Rating:: _4_STAR);
    Car c2(234, 9038.0f, Rating:: _2_STAR);
}