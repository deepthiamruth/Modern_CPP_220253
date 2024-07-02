#include <iostream>
#include <thread>
#include <mutex>

int32_t m_amount{1000};

std:: mutex mt;

void Deposit(){
    for (int i=0; i<100;i++){
        std:: this_thread ::sleep_for (std::chrono::milliseconds(5));
        mt.lock();
        m_amount +=10;
        mt.unlock();
    }
}

void Withdraw(){
    for(int i=0;i<100;i++){
         std:: this_thread ::sleep_for (std::chrono::milliseconds(5));
        mt.lock();
        m_amount -=10;
        mt.unlock();
    }
}

int main(){
    // Deposit();
    // Withdraw();

    std:: thread t1 {&Withdraw};
    std:: thread t2 {&Deposit};

    t1.join();
    t2.join();
    std:: cout << "Final amout is : " <<  m_amount  << "\n";
}