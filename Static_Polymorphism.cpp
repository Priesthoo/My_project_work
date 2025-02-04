#include<iostream>
using namespace std;
//Defining an Adapter pattern, This pattern establishes relationships between two imcompatible class interfaces
template<class T>
class Clone{
    public:
    T clone() {
        return static_cast<T*>(this)->make_clone();
    }
};
template<class T>
class CommonInterface{
    public:
    CommonInterface()=default;
    void Do_Work(){ //This will be a common interface that will be shared by the inheritors of the class 
        static_cast<T*>(this)->do_work();
    }
    ~CommonInterface(){
        std::cout<<"Destroying CommonInterface"<<std::endl;
    }
};
template<class T>
class AnotherInterface{
    public:
    AnotherInterface()=default;
    void DoWork(){
        static_cast<T*>(this)->Dowork();
    }
    ~AnotherInterface(){
        std::cout<<"Destroying AnotherInterface"<<std::endl;
    }
};
//First Imcompatible Interface
class BRDF:public CommonInterface<BRDF>{
    public:
    BRDF()=default;
    void do_work(){
        std::cout<<"Implementing BRDF"<<std::endl;
    }
    ~BRDF(){
        std::cout<<"Destroying BRDF"<<std::endl;
    }
};
//Second Imcompatible Interface
class BTDF:public AnotherInterface<BTDF>{
    public:
    BTDF()=default;
    void Dowork(){
        std::cout<<"Implementing BTDF"<<std::endl;
    }
    ~BTDF(){
        std::cout<<"Destroying BTDF"<<std::endl;
    }
    
};
//The adapter that groups the two imcompatible interfaces.Achieved by Multiple Inheritance.
class BSSDF:public BTDF,public BRDF{
    public:
    BSSDF()=default;
    void do_work(){
        std::cout<<"Implementing   BRDF "<<std::endl;
    }
    void Dowork(){
        std::cout<<"Implementing BSDF"<<std::endl;
    }
    ~BSSDF(){
        std::cout<<"Destroying BSSDF"<<std::endl;
    }
};

