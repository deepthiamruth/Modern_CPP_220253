#include <iostream>
#include <vector>
#include<functional>
#include <thread>
#include <mutex>//ordinary , binary semaphor

std:: mutex mt;
using logic = std:: function <void (int number)>;

void Adaptor(logic fn , const std:: vector<int>& data){
    for(int val : data){
        std:: this_thread::sleep_for(std:: chrono::seconds(1));

        fn(val);
    }
}
void Square(int number){
    mt.lock() ;
    std:: cout << number * number <<"\n";
    mt.unlock();
}

int main(){
    auto cube_fn = [](int number){
        mt.lock();
        std:: cout << number* number * number <<"\n";
        mt.unlock();
    };

   
    std:: thread t1{&Adaptor, &Square , std:: vector <int> {1,2,3,4,5}};
    std:: thread t2 {&Adaptor, cube_fn, std:: vector <int> {1,2,3,4,5}}; 
    
    
    t1.join(); //main cannot proceed beyond line 27 unless t1 is terminated/completed
    t2.join(); //main cannot proceed beyond line 28 unless t2 is terminated/completed
}
