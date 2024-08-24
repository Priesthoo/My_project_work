#include<iostream>
using namespace std;
class Base{
    private:
    const char* base_name;
    int uid;
    public:
    Base()=default;
    Base(const char*ch,const int uid1){
        base_name=ch;
        uid=uid1;
       }
    Base(const Base& base){
        base_name=base.base_name;
        uid=base.uid;
    }
    virtual bool is_base_name() const{
        if(base_name){
            return true;
        }
        return false;
    }
    const char* get_base_name() const {
        return base_name;
       }
      int unique_id () const {
          return uid;
      }
    const char& get_base(){
        return *base_name;
    }
    int& get_unique(){
        return uid;
    }
    void set_whole(const char*b,const int& idx){
        base_name=b;
        uid=idx;
    }
 };
// Now, Base is a base class specifier for Root, Root will inherit all propertied of Base
class Root:public Base{
    public:
    Root():Base(){
    }
    bool is_base_name() const override{
        cout<<get_base_name()<<endl;
    }
  };
//using raw pointers
void set_base(Base*base,const char*b,const int& idx){
    if(base==nullptr){
        return;
    }
    base->set_whole(b,idx);
    
}
//using Smart pointers
#include<memory>
void set_base(shared_ptr<Base>&ptr,const char*b,const int& idx){
    if(ptr.get()==nullptr){
        return;
    }
    ptr.get()->set_whole(b,idx);
}