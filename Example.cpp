#include<iostream>
#include<vector>
using namespace std;


//For static polymorphism
template<class T>
class Implementer{
    public:
    void update_value(const int& value){
        static_cast<T*>(this)->update(value);
    }
};

//The Observer Pattern
class Observer:public Implementer<Observer>{
    public:
    bool is_listening;
    Observer()=default;
    void update(const int& value) const {
       Display(value);
       return;
    }
    void Display(const int& value) const{
        std::cout<<"The current value: "<<value<<std::endl;
        return;
    }
    void isListening(bool truth){
        is_listening=truth;
        return;
    }
    
};

//Subject that manages and maintain a list of observers,,This class emits signals
class Subject{
    public:
    Subject()=default;
    std::vector<Observer> observers;
    
  void ChangeValue(const int& value1){
      value=value1;
      NotifyObservers(value1);
      }  
      //To add new observers
   void Add_Observer(const Observer& observer){
       observers.push_back(observer);
       return;
   }
   //To remove Observers
   void Remove_Observer(){
       if(observers.size()==0){
           return;
       }
       observers.pop_back();
       return;
   }
   //To notify the observers that change had occured 
   void NotifyObservers(const int& value1){
       if(observers.size()==0){
           return;
       }
       for( auto observer:observers){
          if(observer.is_listening==true){
          observer.update_value(value1);    
          }
       }
   }
   
 private:
 int value;
};



int main(int argc, char *argv[])
{
	Subject sub;
	Observer observer;
	Observer observer1;
	observer.isListening(true);
	observer1.isListening(true);
	sub.Add_Observer(observer);
	sub.Add_Observer(observer1);
	sub.ChangeValue(13);
	sub.Remove_Observer();
	sub.ChangeValue(15);
}