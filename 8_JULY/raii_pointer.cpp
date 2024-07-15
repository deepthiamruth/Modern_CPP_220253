#include <iostream>
#include<list>


void CreateData(std::list <int> & data){
    data.emplace_back (10);
    data.emplace_back(20);
}

void CalculateTotal(std:: list <int> & data){
    if(data.empty()){
        throw std::invalid_argument("Data is Empty");
    }
    float total {0.0f};
    for(int val : data){
        total +=val;
    }
    std:: cout << "total is :" << total << "\n";
}

void PrintFisrtElement(std::list <int> & data){
    if(data.empty()){
        throw std::invalid_argument("Data is Empty");
    }
    std:: cout << data.front();
}

int main(){
    std::list <int> data {};
    CreateData(data);
    CalculateTotal(data);
    PrintFisrtElement(data);
    //we will exit from main function
}