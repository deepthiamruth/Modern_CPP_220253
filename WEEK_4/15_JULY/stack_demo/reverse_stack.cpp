#include <optional>
#include<stack>
#include <iostream>
std::optional<std::string> StackReverse(std::string& data) {

    std::stack<char> reversed_char {};

    for(const char c : data) {

        reversed_char.push(c);

    }
 
    std::string result {};

    while(!reversed_char.empty()) {

        result = result + reversed_char.top();

        reversed_char.pop();

    }

    if(result.empty()) {

        return std::nullopt ;

    }

    return result;

}
 
void TakeIp(std::string& data) {

    std::cin >> data;

}
 
int main() {

    std::string data {};

    TakeIp(data);
 
    if(auto result = StackReverse(data); result.has_value()) {

        std::cout << result.value() << "\n";

    }

    else {

        std::cerr << "Blank input\n" ;

    }

}
 