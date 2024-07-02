#include <iostream>
#include<thread>
#include<functional>
#include<vector>
using operation = std::function <int(int number)>;
using Array = std:: array<int,10>;

Array result {0};

void Adaptor(operation fn , const std:: vector<int>&data, int k){
    for(int val : data){
        std:: this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = fn(val);
    }
}

int square(int number){
    return number*number;
}

int main(){
    auto cube_fn = [](int number){return number*number*number;};

    std::thread t1 {&Adaptor, &square , std:: vector <int> {1,2,3,4,5}, 0};
    std::thread t2 {&Adaptor, &square , std:: vector <int> {1,2,3,4,5}, 5};

    t1.join();
    t2.join();

    for(int val : result){
        std:: cout <<val << "\n";
    }

}
