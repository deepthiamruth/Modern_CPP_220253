#include<unordered_map>
#include<iostream>
#include "Employee.h"
#include <functional>

//names of products attached to a numeric serial number for each 
using m_pair = std::pair <const unsigned int, Employee>;
using Predicate = std::function < bool (const m_pair&)>;
using Container = std::unordered_map<unsigned int , Employee>;


//iterators : idea of going one element to other without worring about the actual process involved


//cpp 17 
void DisplayMapUsingStructureBinding(const Container& data){
    for(auto & [k,v] : data)
    std::cout << "Key is : " << k << " value is: " << v <<"\n";
}


void CreateEmployeeObjects(Container & data){
    data.emplace( //<int , Employee>
        std::piecewise_construct, //construct by considering by 2 pieces
        std::forward_as_tuple(101), //first piece is a tuple of 1 key
        std::forward_as_tuple(101, "Deepthi", 9000.0f,22, 1 )
    ); //second piece is a tuple of 5 items

    data.emplace( //<int , Employee>
        std::piecewise_construct, //construct by considering by 2 pieces
        std::forward_as_tuple(102), //first piece is a tuple of 1 key
        std::forward_as_tuple(102, "Harshith", 904570.0f,28, 7)
    ); //second piece is a tuple of 5 items


    data.emplace( //<int , Employee>
        std::piecewise_construct, //construct by considering by 2 pieces
        std::forward_as_tuple(103), //first piece is a tuple of 1 key
        std::forward_as_tuple(103, "Sreeja", 998620.0f,32, 2)
    ); //second piece is a tuple of 5 items
}

void FindAveargeSalary(const Container& data){
    //for every pair of key and value, go to value section and use the getter to fetch salary.
    //Add salary to total at the end for loop , divide total by size of hash table
    float total{0.0f};
    for(auto& [k,v]:data){
        total+= v.salary();
    }
    std::cout << total/data.size() << "\n";
}

void FindEmployeeById(const Container& data, unsigned int key){
    //std::unordered_map<unsigned int, std::string> :: const_iterator itr = data.find(key);

    auto itr = data.find(key);

    if(itr == data.end()){
        std::cerr << "Employee with given key : " << key << "is not found\n";
    }else{
        std::cout  << itr -> second << "\n";
    }
}

//do not  apply filter on key , condition is based on object's value
//while extracting pairs from an unordered map , the key part shall always be const!
void FilterEmployeeByPredicate(const Container& data, Predicate fn){
    for(const m_pair& p :data ){
        if(fn(p)){
            std::cout <<p.second << "\n";
        }
    }
}

int main(){
    Container data;
    CreateEmployeeObjects(data);
    DisplayMapUsingStructureBinding(data);
    FindAveargeSalary(data);
    FindEmployeeById(data, 101);

   // FilterEmployeeByPredicate(data,[](const std::pair<const unsigned int, Employee>& p){ return p.second.age()>30;});
    FilterEmployeeByPredicate(data,[](const m_pair& p){ return p.second.age()>30;});
}