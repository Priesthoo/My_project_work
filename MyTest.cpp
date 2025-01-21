#include<fstream>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;
//The are the options to be used to open,close,read from and write to file.
 struct OPTIONS{
    static const unsigned int open=1<<1;
    static const unsigned int close=1<<2;
    static const unsigned int write=1<<3;
   static const unsigned int  read=1<<4;
};
//This function Tests the configured options
void TestOptions(const unsigned int&  option){
    if(option & OPTIONS::open){
        std::cout<<"File is opened "<<endl;
    }
    if(option & OPTIONS::close){
        std::cout<<"File is closed"<<std::endl;
    }
    if(option & OPTIONS::write){
        std::cout<<"File can be written to"<<endl;
    }
    if (option & OPTIONS::read){
        std::cout<<"File can be read from"<<std::endl;
    }
}
template<class T>
class Book{
 public:
    bool is_read(){
        static_cast<T*>(this)->read();
    }
};
class Draw_Book:public Book<Draw_Book>{
    public:
    void read(){
        cout<<"Book is opened for reading"<<std::endl;
    }
};


int main(int argc, char *argv[])
{   //This uses open and close feature to enable both opening and closing
     int open_file=(OPTIONS::open|OPTIONS::close);
     TestOptions(open_file);
     
     std::cout<<std::endl;
     //This removes the close feature which only enables the opening feature.
     open_file&=~(OPTIONS::close);
   
     TestOptions(open_file);
     
}