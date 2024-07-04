#include "Operations.h"

DataContainer Operations::m_data{};
ThreadContainer Operations:: m_threads{};
std:: mutex Operations :: mt{};
void Operations::CreateCarsAndBikes()
{
    m_data.emplace_back(new Car("c6701", 89374.9f, 4));
    m_data.emplace_back(new Car("c6702",786324.6f, 3 ));
    m_data.emplace_back(new Car("c6703", 89374.7f, 1));
    m_data.emplace_back(new Bike("b6601", 76237.7f));
    m_data.emplace_back(new Bike("b6602", 7637.6f));
}

void Operations::FindAverageCost()
{
    if(m_data.empty()){
        mt.lock();
        std:: cerr << "Empty data\n";
        mt.unlock();
    }

    float total {0.0f};
    for(const VrType v: m_data){
        std:: visit ([&] (auto && val ) {total += val->getprice();}, v);
    }
    if(!m_data.empty()){
        mt.lock();
        std:: cout << "Average is :" << total/m_data.size() << "\n";
        mt.unlock();
    }
}

std::optional<VrType> Operations::ReturnMatchingInstance(std::string id)
{
    if(m_data.empty()){
        std:: cerr <<"empty data container\n";
    }
    std:: optional <VrType> result {std:: nullopt};
    bool m_id_found{false};
    for(const VrType v :m_data){
        std:: visit ([&] (auto&& val){if (val-> getid() == id){
            result = v; m_id_found = true;
        }}, v);
        if(m_id_found){
            break;
        }
    }
    return result;
}

void Operations::Deallocate()
{
    if(m_data.empty()){
        std:: cerr <<"Empty data container\n";
    }
    for(const VrType v : m_data){
        std:: visit([] (auto&& val){delete val;}, v);
    }
}

void Operations::DisplayInsuranceAmount()
{
    if(m_data.empty()){
        mt.lock();
        std:: cerr << "Empty data\n";
        mt.unlock();
    }
    for(VrType v : m_data){
        std:: visit ([] (auto && val) {
            mt.lock();
            std:: cout << "Insurance Amount " << val -> InsuranceAmount() <<"\n";
            mt.unlock();
        }, v);
    }
}

std::optional<unsigned int> Operations::FindSeatCountForGivenId(std::string id)
{
    if(m_data.empty()){
        std:: cerr << "Empty data\n";
    }
    std::optional<unsigned int> result {std:: nullopt};
    bool matchFound{false};

    for(const VrType v :m_data){
        if(std::holds_alternative<Car*>(v)){
            Car* temp = std::get<0> (v);

            if(temp->getid() == id){
                matchFound = true;
                result = temp-> getseatCount();
            }
        }
    }
    if(!matchFound && !m_data.empty()){
        std:: cerr << "Id was not found\n";
    }
    return result;
}

 void Operations::MapThreads()
{
    m_threads.emplace_back(Operations:: FindAverageCost);
    //m_threads.emplace_back(Operations::ReturnMatchingInstance , "c6702");
    m_threads.emplace_back(Operations::DisplayInsuranceAmount);
    //m_threads.emplace_back(Operations::FindSeatCountForGivenId, "b6601");

}

void Operations::JoinThreads()
{
    for(std::thread& th : m_threads){
        if(th.joinable()){
            th.join();
        }
    }
}
