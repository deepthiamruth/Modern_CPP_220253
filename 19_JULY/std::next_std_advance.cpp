#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

//vectors and arrays ->random access
//list = random access
//objective : Node
int main(){
    //objective: move iterator on container which doesn't support random access without manually writing for loops

    std::list<int >data {1,2,3,4,5,6,7};
    auto itr = data.begin();
    auto new_itr = std::next(itr, data.size() - 3);
    std::advance(itr, data.size()- 3); //itr will be modified to new position . //no new variable created
}
