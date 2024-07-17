#ifndef Car_H
#define Car_H

#include <iostream>

class Car
{
private:
   std:: string m_id{""};
   float m_price{0.0f};
   unsigned int m_seat_count{0};
public:
    Car() = delete;
    ~Car()=default;
    Car (const Car & ) = delete;
    Car(Car&& ) = delete;
    Car& operator = (const Car &) = delete;
    Car& operator = (Car&&) = delete;
    float InsuranceAmount();

    Car(std:: string id, float price, unsigned int seats);
    
    std:: string getid() const { return m_id; }

    float getprice() const { return m_price; }

    int32_t getseatCount() const { return m_seat_count; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price
           << " m_seat_count: " << rhs.m_seat_count;
        return os;
    } 
};



#endif // Car_H
