 /*
Execute tasks in asynchronous mode
It is a thread that can also catch a return value so could be used in cpp to execute value returning functions in a seperate thread as well
*/

#include <iostream>
#include <future> //cpp 11 
int64_t Magic(int32_t number ){
    return number * number;
}

int main(){
    std:: future <int64_t> ans = std::async(&Magic, 10 );

    //main will block at this line till completion of magic function
    std:: cout << ans.get() <<"\n"; // get fetches the answer from the async thread.
}