/*
    use case 1: calculate sq for 10 nums
    10 std::thread object to compute sq of num of each 

    5 opertaions are to be performed , all are independent (order of execution are not imp ). Execute all 5 parallely 

    a) one std::thread for each operation


*/ 

#include <iostream>
#include<thread>
#include <condition_variable>
#include <mutex>

int32_t value {0};
std::condition_variable cv;
bool m_inputReceived{false};
std:: mutex mt;
void Producer(){
    
    while(!m_inputReceived){
        std:: cin >> value ;
        if(value >5){
            m_inputReceived = true;
        }
    }
    std:: lock_guard <std::mutex> lg (mt);
    cv . notify_one ();

}

void Consumer(){

    //waitung for signal 
    std::unique_lock<std:: mutex> ul {mt};

    cv.wait(ul, []() {return m_inputReceived; });
    //this line cannot be computed before producer gives a signal
    std:: cout << "Value squared is :" << value * value << "\n";
}

int main(){ //thread!!!

    //will launch producer
    std::thread t1 {&Producer}; // execute seperately from main t1 and t2 are handles
    std::thread t2 {&Consumer};

    std::cout << "Main continues" << "\n";
    std::cout << "Main can literally do anything" << "\n"; 
    //in the background t1 and t2 are running

    t1.join();
    t2.join();

    std:: cout << "Thats all . Good bye!" << "\n";

    //will launch consumer



}

/*
3 perspectives

a) I created t1 thread
b) I created t2 thread
c) first cout 
d) second cout 
e) t1 join
f) t2 join
g) good bye cout 
h) terminate app!


producer perspective

a) executed a loop . In loop till m_input)received is true:
    a1) took a input
    a2) checked if input is greater > 5 , make flag true

b) acquire a mutex so that nobody disturbs
c) send a signal via notify_one() // one of the 


consumer perspective

a) I am waiting for 
*/