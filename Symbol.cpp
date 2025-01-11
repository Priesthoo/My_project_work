#include<fstream>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;
 struct OPTIONS{
    static const unsigned int open=1<<1;
    static const unsigned int close=1<<2;
    static const unsigned int write=1<<3;
   static const unsigned int  read=1<<4;
};
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


int main(int argc, char *argv[])
{ 
   int option=(OPTIONS::open| OPTIONS::close| OPTIONS::write|OPTIONS::read);
    
   TestOptions(option);
}