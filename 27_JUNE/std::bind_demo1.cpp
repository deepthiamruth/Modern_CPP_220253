/*
    std:: bind allow us to "refactor"/ "repurpose" / "remodel" an existing function to create "partially - implemented " functions
*/

/*
    cp -r  source  destination
*/

#include<iostream>
#include<functional>

void formula(int x, int y , int z){
    std:: cout << ((x+y) - z);
}

int main(){
    formula(10,20,30);

    auto partial_formula = std:: bind(& formula, 100, std:: placeholders:: _1, std:: placeholders::_2);

    partial_formula(10,90); //formula(100,10,90);


    auto swap_formula = std::bind(& formula, std:: placeholders :: _2, std:: placeholders::_3, std:: placeholders::_1);

    swap_formula(10,20,30); // formula(20,30,10);

   auto  weiredly_mapped_formula = std::bind (&formula, 100, 200 , std::placeholders::_2);
   weiredly_mapped_formula(99,10); // 99 is discarded because _1 was not used

}