#include<iostream>
#include<functional>

int main(){
    auto fn = [] (int32_t number , int32_t factor){
        return number* factor;
    };
    auto partially_implemented_fn = std::bind(fn, 100 , std::placeholders:: _1);

    partially_implemented_fn(20); // fn(100,20);

    partially_implemented_fn(20, 3, 123, 45); // fn(100,20);  //all other inputs are discarded

    auto weirdly_mapped_fn = std::bind(&fn, 100, 200 , std::placeholders:: _2 );
}