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
    static BankAccount * m_instance_ptr;
    BankAccount() = default;
    BankAccount(const BankAccount &) = delete;
    BankAccount(BankAccount &&) = delete;
    BankAccount operator=(const BankAccount &) = delete;
    BankAccount &operator=(BankAccount &&) = delete;
    BankAccount(int amount) : m_amount{amount}
    {
    }

public:
    ~BankAccount() = default;
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
   
   
   

    static BankAccount* GetInstance(int val){
        if(m_instance_ptr)
        {
            m_instance_ptr -> setAmount(val);
            return m_instance_ptr;
        }
        else{
            m_instance_ptr = new BankAccount(val); // default construction
            return m_instance_ptr;
        }
    }

    int getAmount() const { return m_amount; }
    void setAmount(int amount) { m_amount = amount; }

    
};


BankAccount* BankAccount:: m_instance_ptr{nullptr};

void CreateThreads(ThreadContainer& threads , BankAccount & b1){
    threads.emplace_back(&BankAccount::Deposit,&b1);
    threads.emplace_back(&BankAccount::Withdraw,&b1); 

}
void JoinThreads(ThreadContainer & threads ){
    for(std:: thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}

void DisplayFinalAmount(BankAccount& b1){
    std:: cout << "Final Amount:" << b1.getAmount() << "\n";
}


int main(){
    BankAccount * ptr = BankAccount:: GetInstance(1000);
    ThreadContainer threads{};
    CreateThreads(threads, *ptr);
    JoinThreads(threads);
    DisplayFinalAmount(*ptr);
    delete ptr;
}