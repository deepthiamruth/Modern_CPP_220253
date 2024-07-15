/*
    thread: Isolated unit of instructions
    executing in memory
*/
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

std:: mutex mt;

void square(int num){
    std::lock_guard<std::mutex> lg(mt);
    std::cout <<num*num << "\n";
}

class Dummy
{
private:
   
public:
    Dummy() = default;
    ~Dummy()= default;

    void DisplayFact(unsigned int val){
        if(val == 1 || val ==0){
            std::lock_guard<std::mutex> lg(mt);
            std::cout << 1 << "\n";
        }
        else{
            unsigned int result {1};
            for(unsigned int i =2 ; i<= val ; i++){
                result *= i;
            }
            std::lock_guard<std::mutex> lg(mt);
            std::cout << result << "\n";
        }
    }
    static void MultiplyBy100(int num){
        std::lock_guard<std::mutex> lg(mt);
        std::cout << num*100 <<"\n";
    }
};


auto f1 = [](int number){ std::lock_guard<std::mutex> lg(mt); std:: cout << number* number* number << "\n";};

void MapThreads(std::vector <std::thread> & threads){
    threads.emplace_back(std::thread(&square, 10)); //regular
    threads.emplace_back( std::thread (f1 , 7)); //lambda
    threads.emplace_back(std::thread(Dummy::MultiplyBy100, 10)); //static
    Dummy d1{};
    threads.emplace_back(std::thread (&Dummy:: DisplayFact, &d1 , 5)); //non - static
}

void JoinThreads(std::vector <std::thread> & threads){
    for(std::thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}

int main(){
    std::vector<std::thread> threads{};
    MapThreads(threads);
    JoinThreads(threads);
}

