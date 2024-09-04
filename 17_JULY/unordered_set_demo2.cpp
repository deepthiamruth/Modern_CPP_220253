#include<iostream>
#include<unordered_set>
#include "Employee.h"

int main(){
   auto hash_fn = [](const Employee& e){return std::hash<unsigned int>()(e.id());};
   auto eq_fn = [](const Employee& e1, const Employee& e2){
    return e1.id() == e2.id();
   };

   std::unordered_set<Employee , decltype(hash_fn), decltype(eq_fn)> s{3, hash_fn, eq_fn};
    s.emplace(101, "deepthi", 98374.9f, 22, 1.0f);
    s.emplace(101, "sreeja", 98764.9f, 23, 3.0f);
    s.emplace(102, "deepthi", 98374.9f, 22, 1.0f);

    for(const Employee& e:s){
        std::cout << e <<"\n";
    }
}
