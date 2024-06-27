#include<iostream>


// void Magic(int data){
//     std:: cout << "int :" << data;
//     data =30;
//     // std:: cout << "int:" << data;
// }

// void Magic(int& data){
//     std:: cout << "int& :" << data <<"\n";
// }

// void Magic(int && data){
//     std:: cout << "int &&  :" << data;
//     data =20;
// }

// void Magic(const int& data){
//     std:: cout << "const & :" << data;
//      //data = 20;
//     //std::cout << "data = " << "\n";
    
// }

void Magic(const int&& data){
    std:: cout << "const && :" << data;
    //
}

int main(){
    Magic(10);
    int n1=20;
    Magic(n1);
    

}