// include things here
#include <iostream>
#include <functional>
#include <vector>
///////////////////


///////// create aliases

using Logic= std:: function <void (const std:: string &)>;
using DataContainer = std::vector <std:: string>;
///////////////



// declare and define the adaptor logic here
void Adaptor(const Logic func , DataContainer & data){
if(data.empty()){
    std:: invalid_argument ("Null\n");
}

    for(const std:: string st : data){
        func(st);
    }
}


void FindVowels(const std:: string& val){
    if (val == ""){
        std:: cerr << "Cannot Find Vowels\n";
        return;
    }
    bool atleastOneVowelFound{false};
    for(char c: val){
        if( c == 'A' || c == 'a' || c == 'E' || c == 'e'|| c== 'I' || c == 'i' || c== 'O' || c=='o' || c== 'u' || c=='U' ){
            atleastOneVowelFound = true;
            std:: cout << c << "\t";
        }
    }
    if(!atleastOneVowelFound){
        std:: cerr << "Not a single vowel found";
    }
}

void DisplayLastThreeCharacters(const std:: string & val){
    for(char c: val){
        
    }


}




int main(){
    std:: vector <std:: string> data1 {" " , "data", "abc" , "xyz"};
    std:: vector <std:: string> data2 {"" , "", "" , ""};
    std:: vector <std:: string> data3 {};

    try{
        Adaptor(&FindVowels, data1);
        Adaptor(&FindVowels, data2);
        Adaptor(&FindVowels, data3);
    }catch(std:: invalid_argument & ex){
        std:: cerr << ex.what();
    }


    Adaptor ( [] (const std:: string & st) { std:: cout << st.length();}, data1);
}






// demonstrate code here
