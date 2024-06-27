#include <iostream>
#include <vector>
#include <functional>

void Magic(int & data){
    std:: cout <<data;
}

int main(){
    int n1 =10;
    std::reference_wrapper<int> ref {n1};
    int& ref = n1; // ref is a reference to n1

    std:: reference_wrapper<int> ref = n1;

    // ref is an alternate name for n1 in main function

    Magic(ref); // int& data = n1;

    //int& arr[1] {ref};

    std:: vector <int&> v1 {ref};
    std:: vector <std:: reference_wrapper<int>> v1;

}