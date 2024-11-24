/*
    thread: Isolated unit of instructions
    executing in memory
*/
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include <future>
std:: mutex mt;

int square(int num){
    std::lock_guard<std::mutex> lk(mt);
    return num*num ;
}

class Dummy
{
private:
   
public:
    Dummy() = default;
    ~Dummy()= default;

    int DisplayFact(unsigned int val){
        if(val == 1 || val ==0){
            std::lock_guard<std::mutex> lg(mt);
            return 1;
        }
        else{
            unsigned int result {1};
            for(unsigned int i =2 ; i<= val ; i++){
                result *= i;
            }
            std::lock_guard<std::mutex> lg(mt);
            return result;
        }
    }
    static int MultiplyBy100(int num){
        std::lock_guard<std::mutex> lg(mt);
        return num*100 ;
    }
};


auto f1 = [](int& number){ std::lock_guard<std::mutex> lg(mt); return number* number* number ;};

void createasync(std::vector <int>& results){
    int n1{10};

    Dummy d1{};
    std::future<int> result1= std::async(&square , 10);
    std::future<int> result2 = std::async(f1, std::ref(n1));
    std::future<int> result3 = std::async(&Dummy:: DisplayFact , &d1, 5);
    std::future <int> result4 = std::async (&Dummy::MultiplyBy100, 20);

    results.emplace_back(result1.get());
    results.emplace_back(result2.get());
    results.emplace_back(result3.get());
    results.emplace_back(result4.get());
    
}

int main(){
    
    int n1{10};
    Dummy d1{};

    std::vector <int> results;

    createasync(results);
    for(int& e : results){
        std::cout << e << "\n";
    }

    // std::future<int> result1= std::async(&square , 10);
    // std::future<int> result2 = std::async(f1, std::ref(n1));
    // std::future<int> result3 = std::async(&Dummy:: DisplayFact , &d1, 5);
    // std::future <int> result4 = std::async (&Dummy::MultiplyBy100, 20);

    // std::cout << result1.get() << "\n";
    // std::cout << result2.get() << "\n";
    // std::cout << result3.get() << "\n";
    // std::cout << result4.get() << "\n";
}

