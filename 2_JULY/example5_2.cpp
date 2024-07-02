#include <iostream>
#include <thread>
#include <mutex>
class BankAccount
{
private:
    std::mutex mt{};
    int m_amount{1};

public:
    BankAccount() = default;
    BankAccount(const BankAccount &) = delete;
    BankAccount(BankAccount &&) = delete;
    BankAccount operator=(const BankAccount &) = delete;
    BankAccount &operator=(BankAccount &&) = delete;
    ~BankAccount() = default;

    BankAccount(int amount) : m_amount{amount}
    {
    }

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

    int getamount() const { return m_amount; }
};

int main()
{
    BankAccount b1{1000};
    std::thread t1{&BankAccount::Withdraw, &b1};
    std::thread t2{&BankAccount::Deposit, &b1};

    t1.join();
    t2.join();
    std:: cout << "Final amout is : " <<  b1.getamount()  << "\n";
}
