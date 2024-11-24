#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <mutex> //a binary semaphore
 
//Create a mutex object
std::mutex mt;
 
using operation = std::function<void (int number)>;
 
 
void Adaptor(operation fn, const std::vector<int>& data) {
    for(int val : data) {
        std::this_thread :: sleep_for(std::chrono :: seconds(1));
       fn(val);
    }
}
 
 
void Square(int number) {
    //a shared resource i.e cout is a shared resource
 
    mt.lock(); //ask for the permission to access cout
    std::cout << number*number << "\n";
    mt.unlock(); //release the lock when done
}
 
int main() {
    auto cube_fn = [] (int number) {
        //a shared resource
        mt.lock();
        std::cout << number*number*number << "\n";
        mt.unlock();
        };
 
   // auto cube_fn = [] (int number) { return number*number*number ; };
 
 
    std::thread t1 { &Adaptor, &Square, std::vector<int> {1,2,3,4,5} }; // Address of adaptor followed by its parameters
    std::thread t2 { &Adaptor, cube_fn, std::vector<int> {1,2,3,4,5} }; // since cube is a lambda function do not use &
    t1.join(); //main cannot proceed beyond line 35 unless t1 is terminated/completed
    t2.join(); //main cannot proceed beyond line 36 unless t2 is terminated/completed
 
}