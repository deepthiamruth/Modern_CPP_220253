#include "Functionalities.h"

/*
    Createa the objects and store in vector
*/

void CreateObjects(Container& data) {

    std::vector<ProtocolType> p1 = {ProtocolType::CAN, ProtocolType::ETHERNET};
    data.emplace_back(std::make_shared<Analog>("a1", SystemType::BLUETOOTH,p1, true));

    std::vector<ProtocolType> p2 = {ProtocolType::CAN, ProtocolType::ETHERNET, ProtocolType::LAN};
    data.emplace_back(std::make_shared<Analog>("a2", SystemType::BLUETOOTH_WIFI,p2, false));

    data.emplace_back(std::make_shared<Digital>("d1",ConnectType::ANDROID_AUTO, 45.2f, true));

    data.emplace_back(std::make_shared<Digital>("d2",ConnectType::WEB_OS, 95.2f, false));
}

/*
    Function to display the instances of given connect type
*/
void DisplayMatchingInstance(Container &data, ConnectType connect_type)
{
    //Flag varaibles to check if digital multimedi and connect type are found
    bool digital_found {false};
    bool connectType_found {false};

    //if data is empty
    if(data.empty()) {
        std::cerr << "Empty container\n";
    }
    else {
        for( std::variant<std::shared_ptr<Analog>, std::shared_ptr<Digital>>& v : data ) {
            //check if current object is digital type
            if(std::holds_alternative<std::shared_ptr<Digital>>(v)) {
                std::shared_ptr<Digital> temp = std::get<1>(v);
                digital_found = true;
                if(temp->smartConnectType() == connect_type) {
                    //check if the current objects connetType matches the given one
                    connectType_found = true;
                    std::cout << "Matching Instance : " << *temp << "\n";
                }
            }
        }
    }

    //If none of the objects are og digitalMultimedia type
    if(!digital_found) {
        std::cerr << "No object is DigitalMultimedia type\n";
    }

    //If digital objects found but type doesn't match
    if(digital_found && !connectType_found) {
        std::cerr << "DigitalMultimedia objects found but not matching connectType found\n";
    }

}

/*
    Function to return the system type for given object id
*/

std::optional<SystemType> FindSystemTypeById(Container &data, std::string id)
{
    //A result variable 
     std::optional<SystemType> result {std::nullopt};
     SystemType ans {};

    //Flag varaibles
     bool analog_found {false};
     bool id_found {false};

    //if data is empty
     if(data.empty()) {
        std::cerr << "Empty data container\n";
     }

     else {
        for( std::variant<std::shared_ptr<Analog>, std::shared_ptr<Digital>>& v : data ) {
            //check if curent object is analig type
            if(std::holds_alternative<std::shared_ptr<Analog>>(v)) {
                std::shared_ptr<Analog> temp = std::get<0>(v);
                analog_found = true;
                if(temp->systemId() == id) {
                    //check if the id matches the current objects id
                    id_found = true;
                    ans = temp->systemType();
                    //if so store in result variable
                    result = ans;
                }
            }
        }
     }

     //if none of the object is analog type
     if(!analog_found) {
        std::cerr << "No object is DigitalMultimedia type\n";
    }

    //analog objects are present but id doesn't match
    if(analog_found && !id_found) {
        std::cerr << "DigitalMultimedia objects found but not matching connectType found\n";
    }
    return result;
}

/*
    Funtion to copy last n objects
    Returns a container of n objects
*/
Container CopyLastNObjects(Container &data, unsigned int n)
{
    //a result varaible
    Container result{};

    //if data is empty
    if(data.empty()) {
        std::cerr << "Empty container\n";
    }
    else {
        //check if n value is less than equal to data sie
        if(n<data.size()) {
            for(int i=data.size()-1;i>0;i--) {
                //add the objects to result container
                result.emplace_back(data[i]);
                
                //check if n objects are placed into result
                if(i == n) {
                    break;
                }
            }
        }
        //if n value is greater than size
        else {
            std::cerr << "N is greater than the size of container\n";
        }
    }
    return result;
}
