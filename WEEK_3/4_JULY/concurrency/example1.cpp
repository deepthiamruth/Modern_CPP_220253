#include <thread>
#include<list>
#include <iostream>
#include <functional>
#include <mutex>

std:: mutex mt;
using ThreadContainer = std:: list <std:: thread>;
using DataContainer = std:: list <int32_t>;
using funWrapper = std:: function <void (int32_t)>;


void MapThreads(ThreadContainer& threads ,  DataContainer& data, funWrapper fn){
    // auto itr = data.begin();
    // for(std:: thread & th : threads){
    //     th = std:: thread {fn , *itr++};
    // }

    for(int32_t n :data){
        threads .emplace_back(fn, n);
    }
}

void JoinThreads( ThreadContainer& threads){
    for(std:: thread & th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}

int main(){
    ThreadContainer threads{};
    DataContainer data{10, 20 , 30 ,40};

      auto f1 = [](int32_t number){
        mt.lock();
        std:: cout << number* number << "\n";
        mt.unlock();
        };
    MapThreads(threads, data, f1);
    JoinThreads(threads);

}