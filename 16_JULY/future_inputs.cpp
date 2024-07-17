//remember car music system and maps example

#include<iostream>
#include<future>

int* AllocateSpace(){
    return (int*) new int(); //return the address of the new allocation 
}
int factorial(std::future<int>& number){
    /*
        1. Primary task: calculate factorial (dependent on input)
        2. Make allocation on the heap where the answer will be stored
    */
   int* ans = AllocateSpace();
   /*
      ....Actual ans calculation starts here!
   */
  //after the sub task is complete, input value is MANDATORY NOW!
  int number_value = number.get(); // factorial thread will be blocked until user funfills promise
   int result = 1;
   for(int i=2;i<=number_value;i++){
    result*=i;
   }
   *ans = result; //copy the result on the heap in ans address location
   return result;
}


int main(){
    std::promise<int> pr ;
    std::future<int> ft = pr.get_future();
    std::future<int> res = std::async(&factorial, std::ref(ft));
    int data{0};
    std::cin>>data;

    //funfill promise send a signal to future attacged to this promise
    pr.set_value(data);

    std::cout << res.get() << "\n";

}