#include <iostream>
#include <thread>
#include <mutex>
class BankAccount
{
private:
    static std::mutex mt;
    static int m_amount;

public:
    BankAccount() = default;
    BankAccount(const BankAccount &) = delete;
    BankAccount(BankAccount &&) = delete;
    BankAccount operator=(const BankAccount &) = delete;
    BankAccount &operator=(BankAccount &&) = delete;
    ~BankAccount() = default;

    static void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread ::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount += 10;
            mt.unlock();
        }
    }

    static void Withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread ::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount -= 10;
            mt.unlock();
        }
    }

    //int getamount() const { return m_amount; }

    static int amount() { return BankAccount::m_amount; }
};

std::mutex BankAccount:: mt{};
int BankAccount:: m_amount{900};

int main()
{
    //BankAccount b1{1000};
    std::thread t1{&BankAccount::Withdraw};
    std::thread t2{&BankAccount::Deposit};

    t1.join();
    t2.join();
    std:: cout << "Final amout is : " << BankAccount::amount() ;
}
