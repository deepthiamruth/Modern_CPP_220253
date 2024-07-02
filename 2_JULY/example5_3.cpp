#include <iostream>
#include <thread>
#include <mutex>
#include <list>
using ThreadContainer = std::list <std::thread>;
class BankAccount
{
private:
    std::mutex mt{};
    int m_amount{1};

public:

    void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread ::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount += 10;
            mt.unlock();
        }
    }

    void Withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread ::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount -= 10;
            mt.unlock();
        }
    }
    BankAccount() = default;
    BankAccount(const BankAccount &) = delete;
    BankAccount(BankAccount &&) = delete;
    BankAccount operator=(const BankAccount &) = delete;
    BankAccount &operator=(BankAccount &&) = delete;
    ~BankAccount() = default;

    BankAccount(int amount) : m_amount{amount}
    {
    }

    int amount() const { return m_amount; }
};

void CreateThreads(ThreadContainer& threads , BankAccount & b1){
    threads.emplace_back(&BankAccount::Deposit, &b1);
    threads.emplace_back(&BankAccount::Withdraw, &b1); 

}
void JoinThreads(ThreadContainer & threads ){
    for(std:: thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}

void DisplayFinalAmount(BankAccount& b1){
    std:: cout << "Final Amount:" << b1.amount() << "\n";
}
int main(){
    ThreadContainer threads{};
    BankAccount b1 {5000};
    CreateThreads(threads, b1);
    JoinThreads(threads);
    DisplayFinalAmount(b1);
}