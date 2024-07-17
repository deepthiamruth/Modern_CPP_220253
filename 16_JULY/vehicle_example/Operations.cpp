#include "Operations.h"
std::mutex mt;
void CreateCarsAndBikes(DataContainer& data)
{
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("c6701"),
        std::forward_as_tuple(std::make_shared <Car>("c6701",786324.6f, 3 ))
    );
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("c6702"),
        std::forward_as_tuple(std::make_shared<Car>("c6702",76414.6f, 1 ))
    );
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("b6601"),
        std::forward_as_tuple(std::make_shared<Bike>("b6601", 76237.7f))
    );
    data.emplace(
        std::piecewise_construct,
        std::forward_as_tuple("b6602"),
        std::forward_as_tuple(std::make_shared<Bike>("b6602", 7637.6f))
    );
}

void FindAverageCost(DataContainer & data)
{
    float total{0.0f};
    for(auto& [k,v] : data){
        std::visit([&] (auto && val){
            total+= val->getprice();
        }, v);
    }
    std::cout << total/data.size() << "\n";
}

std::optional<VrType> ReturnMatchingInstance(DataContainer& data, std::string id)
{
    if(data.empty()){
        std:: cerr <<"empty data container\n";
    }
    std:: optional <VrType> result {std:: nullopt};

    auto itr = data.find(id);

    if(itr == data.end()){
        std::cerr << "Employee with given id is not found\n";
    }
    else{
        result = itr -> second ;
    }
    return result;
}


void DisplayInsuranceAmount(DataContainer& data)
{
    if(data.empty()){
        mt.lock();
        std:: cerr << "Empty data\n";
        mt.unlock();
    }
    for(auto& [k,v] : data){
        std::visit([&] (auto && val){
            std::cout << "Insurance Amount is" << val->InsuranceAmount() << "\n";
        }, v);
    }

}

std::optional<unsigned int> FindSeatCountForGivenId( DataContainer& data, std::string id)
{
    if(data.empty()){
        std:: cerr << "Empty data\n";
    }
    std::optional<unsigned int> result {std:: nullopt};
    bool matchFound{false};

    for(auto& [k,v] :data){
        if(std::holds_alternative<std::shared_ptr<Car>>(v)){
            std::shared_ptr<Car> temp = std::get<0> (v);

            if(temp->getid() == id){
                matchFound = true;
                result = temp-> getseatCount();
            }
        }
    }
    if(!matchFound && !data.empty()){
        std:: cerr << "Id was not found\n";
    }
    return result;
}


void MapThreads(DataContainer &data, ThreadContainer &threads)
{
    threads.emplace_back(&FindAverageCost, std::ref(data));
    threads.emplace_back(&DisplayInsuranceAmount, std::ref(data));
}

void JoinThreads(ThreadContainer &threads)
{
    for(std::thread& th : threads){
        if(th.joinable()){
            th.join();
        }
    }
}
