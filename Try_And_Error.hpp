#include<iostream>
using namespace std;
class B{
    public:
    B()=default;
    void Print(int b){
        cout<<"B: "<<b <<std::endl;
    }
};
class A: public B{
    public:
    A()=default;
    void Print(int a){
        cout<<"A:"<<a<<std::endl;
    }
};
class C:public A{
    public:
    C()=default;
    void Print(int c){
        cout<<"C:"<<c<<std::endl;
    }
};

typedef void(A::*method)(int); 
typedef void(B::*Bmethod)(int);
typedef void(C::*Cmethod)(int);
typedef void(* functor)(int);

int main(int argc, char *argv[])
{
    void(A::*method_ptr1)(int)=&A::Print;
    void(B::*method_ptr2)(int)=&B::Print;
    Cmethod Thefunctor=static_cast<Cmethod>(method_ptr2);
    class B b;
    class A a;
    class C c;
    (c.*Thefunctor)(5);
    
}