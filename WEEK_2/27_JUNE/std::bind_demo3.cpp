#include<iostream>
#include<functional>

class Data{
    private:
        int m_value{0};
    public:
        Data() = default;
        Data(const Data&) = delete;
        Data(Data&&) = delete;
        Data& operator= (Data&& ) = delete;
        Data& operator= (const Data& ) = delete;
        ~Data() = default;

        Data (int val) : m_value{val}{

        }
        void DisplayReading(int factor){
            std:: cout << m_value* factor;
        }

        static void Display(int times){
            std:: cout << "Hello World" << times << "times\n";
        }
};

int main(){
    Data obj {18}; // m_value = 18;
    obj.DisplayReading(100);
    auto fn =  std::bind(&Data::DisplayReading, &obj , 100);
    fn(); //obj.

    Data::Display(10); // "Hello world " 10 "times"

    auto binded_static_display = std:: bind (Data:: Display , 10 );
    binded_static_display(); // Data:: Display(10);

}

/*
    for non - static member function

    a)object address is mandatory
    b) it must be the first argument after specifying the name of the function in the bind
    c) you must use & symbol with the name of the member function in bind
    
    For Static member function

    No object involved so no address required
    you should not use & symbol with the name of the function
*/