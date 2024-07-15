#include <iostream>
#include <thread>
#include <mutex> //toy lock mechanism 

class MathOperations
{
private:
    std:: mutex mt{}; // no need to set in constructor 
   int32_t m_value{0};
public:
    MathOperations(const MathOperations&) = delete; 
    MathOperations(MathOperations&&) = delete; 
    MathOperations& operator= (const MathOperations&)= delete;
    MathOperations& operator= (MathOperations&&) = delete; 
    MathOperations () = default;
    ~MathOperations() = default;

    MathOperations(int val) : m_value {val}{}

    void square(){
        mt.lock();
        std:: cout <<"ID of thread square:" << std::this_thread :: get_id() << "\n";
        std:: cout << "Square of " << m_value << " is:" << m_value * m_value << "\n";
        mt.unlock();
    }

    int32_t addition(int other){
        mt.lock();
        std:: cout <<"ID of thread addition:" << std::this_thread :: get_id() << "\n";
        mt.unlock();
        return m_value + other;
    };

    //param param
    int64_t operator()(){
        mt.lock();
        std:: cout <<"ID of thread operation:" << std::this_thread :: get_id() << "\n";
        mt.unlock();
        return m_value * m_value * m_value;
    }
};

int main(){

    MathOperations m1 {100};
   // wrong  std:: thread t1 {&MathOperations :: square , MathOperations{10}};
    std:: thread t1 {&MathOperations :: square , &m1};


    std:: thread t2 {std::ref(m1)}; //thread created by a functor object //operator as a function

    std:: thread t3 {&MathOperations :: addition , &m1 , 100};
    // you cannot capture return value from a function when executing them via std:: thread
   

   t1.join();
   t2.join();
   t3.join();

    // thread takes first parameter as function
    //cannot copy a mutex
    //Note 1: t2 and t3 outputs will get discarded  , no way to capture them 
    //Note 2:  all parameters passed to std:: thread constructor are taken as "call by value"
    //threads cannot capture return value
}
