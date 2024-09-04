#include <vector>
#include <numeric>
#include <iostream>
/*
    v{0,0,0,0,0}
    desired result -- {10,11,12,13,14}
 
*/
 
int main()
{
    std::vector<int>data{1,2,3,4,5};
    std::vector<int> data{5}; //we get only one output bcoz compiler thinks 1 loc with value 5
    std::vector<int> data(5);
    std::iota(
        data.begin(),
        data.end(),
        19
    );
    for(int c: data)
    {
        std::cout<<c<<" ";
    }
}