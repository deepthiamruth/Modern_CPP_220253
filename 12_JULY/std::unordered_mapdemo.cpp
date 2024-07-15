/*
    [  ] [  ]
*/

/*
    key: Attribute or the 



    Hash/Hash value : output of mathematical operation (hash function) applied on key

    e.g : 0,1,2,3 are hash values

    collision : Situation where hash function applied on 2 or more keys coincidently gives the same value 

    collision resolution techniques: Actions that can be taken to resolve collision 
    e.g: Linear probing , double hashing , open chaining , etc
*/
#include<unordered_map>
#include<iostream>

//names of products attached to a numeric serial number for each 

using Container = std::unordered_map<unsigned int , std::string>;

//iterators : idea of going one element to other without worring about the actual process involved


//old cpp way //iterator and increment it or subtract it 
void DisplayMapUsingIterators(const Container& data){
    for(auto itr = data.begin(); itr != data.end(); ++itr){
        std::cout << "Key is :" << itr-> first << "and value is:" << itr->second << "\n";
    }
}

//cpp 17 
void DisplayMapUsingStructureBinding(const Container& data){
    for(auto & [k,v] : data)
    std::cout << "Key is :" << k << "value is:" << v <<"\n";
}

//old way but different //return whole pair
void DisplayMapUsingPair(const Container& data){
    for(const std::pair <unsigned int, std::string > & p :data){
        std::cout << "Key is :" << p.first << "and value is:" << p.second << "\n";
    }
}


int main(){
    Container data{
        {101, "steering wheel"}, //pair of 1 key attached to 1 value
        {102, "Alloy wheels"},
        {103, "Smart mirror ORM"},
        {104 , "360 Camera Setup"}
    };
    DisplayMapUsingIterators(data);
    DisplayMapUsingPair(data);
    DisplayMapUsingStructureBinding(data);
}