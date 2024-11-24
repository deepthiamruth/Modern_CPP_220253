#include <iostream>
#include <vector>
#include <functional>
#include<thread>
using logic = std:: function <void (int)>;

void Adaptor(logic fn , const std:: vector<int> data){
    for(int val : data){
        std:: this_thread::sleep_for(std:: chrono::seconds(1));

        fn(val);
    }
}
void Square(int number){
    std:: cout << number * number << "\n";
}
auto cube_fn =  [] (int number){std:: cout << number*number*number << "\n";};
int main(){
   
    // std:: vector <int > data = {1,2,3,4,5};
    // Adaptor(Square, data);
    // Adaptor(cube_fn, std:: vector <int> {1,2,3,4,5});

    std:: thread t1{&Adaptor, &Square,  std:: vector <int> {1,2,3,4,5}};
    std:: thread t2{&Adaptor, cube_fn,  std:: vector <int> {1,2,3,4,5}}; 
    
    
    t1.join(); //main cannot proceed beyond line 27 unless t1 is terminated/completed
    t2.join(); //main cannot proceed beyond line 28 unless t2 is terminated/completed

}