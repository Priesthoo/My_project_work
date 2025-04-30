 #include<iostream>
#include<string>
#include<list>
#include<memory>
using namespace std;
//To illustrate functions pointers, can we allocate memory on the heap to actually execute the functions
//This file is created to illustrate the concept of event system// Before we create the event system 
typedef int EventType;
class Event;
class Receiver;
class Sender; 
class Object; //this will store the name of the class, 

template<class T,class M>
class Pair{
    public:
    T first_pair;
    M second_pair;
    Pair(const T& s,const M& t):first_pair{s},second_pair{t}{
    
    }
    bool is_Equal_To(const Pair& pair) const {
       if(first_pair==pair.first_pair && second_pair==pair.second_pair){
           return true;
       }
       return false;
    }
    Pair(const Pair& p){
        first_pair=p.first_pair;
        second_pair=p.second_pair;
        
    }
    
};
template<class T,class M>
using Event_Pair=Pair<T,M>;

class Object{
    private:
    string classname;
    public:
    Object()=default;
    void SetClassName(const string& str=string("Object")){
        classname=str;
        return;
    }
    string GetClassName() const{
        return classname;
    }
    
};
//Every other Event that derives from Event class must set SetClassName() to the name of the event,Otherwise,

class Event:public Object{
    private:
    EventType Type;  //this is an event type
    long id;
    Object* orig_object;  //This is the object that sends the event
    public:
    Event(EventType type,const long i):Type{type},id{i}{
        SetClassName(string("Event"));
    }
    void SetEventType(EventType type){
        Type=type;
        return;
    }
    void SetId(const long id1){
        id=id1;
        return;
    }
   void SetOrigin_Object(Object* ob){
       orig_object=ob;
       return;
   }
    EventType GetType() const{
        return Type;
    }
    long GetId() const{
        return id;
    }
    Object* GetOrigin_Object() const{
        return orig_object;
    }
    Event(const Event& event){
        Type=event.GetType();
        id=event.GetId();
        orig_object=event.GetOrigin_Object();
        
    }
    Event& operator=(const Event& event){
         this->Type=event.GetType();
        this->id=event.GetId();
        this->orig_object=event.GetOrigin_Object();
        return *this;
    }
};
//This stores information about the event types and an  event.A single event can produce different Event type....


 template<class EventArg,class Class>
 using Classmethod=void(Class::*)(EventArg& arg);
 
//This maps the Eventtype, Event and the handler together..,Note EventArg represents the event, EventTag represents the type of event.
template<class EventArg,class Class>
class Event_Functor_Mapper{
    
    public:
    Pair<EventArg,Classmethod<EventArg,Class>> eventfunctormapper;
    Event_Functor_Mapper(const EventArg& event,Classmethod<EventArg,Class> method){
        eventfunctormapper.first_pair=event;
        eventfunctormapper.second_pair=method;
        
    }
    Event_Functor_Mapper(const Event_Functor_Mapper& mapper){
       eventfunctormapper.first_pair=mapper.first_pair;
       eventfunctormapper.second_pair=mapper.second_pair;
       
    }
    
};

//This is an event handler, It process all the events and execute it's respective handler, It also binds the callback function to it's event
template<class EventArg,class Class>
class EventHandler{
    std::unique_ptr<Event_Functor_Mapper<EventArg,Class>>Handler;
    long id;  //This stores the id of the event 
    std::unique_ptr<EventHandler<EventArg,Class>> NextHandler; //The Next Handler will hold the Next handler....
    
    public:
    EventHandler(){
        
    }
 //For every event added, There is also a parent handler,
 /*
 Event handler 
 */
 template<class EventTag,class EvtHandler>
   void Bind(const EventTag& evttag,Classmethod<EventArg,Class> method,EvtHandler*handler,long id){
        if(handler==nullptr){
            handler=new EventHandler<EventArg,Class>();
        
        if(handler->Handler.get()==nullptr){
            handler->Handler.reset(new Event_Functor_Mapper<EventArg,Class>);
        }
        //Event Handler 
      handler->Handler->eventfunctormapper.first_pair=Event(evttag,id);
      handler->Handler->eventfunctormapper.second_pair=method;
      handler->id=0;
      return;
        }
  
  EventHandler<EventArg,Class>::Bind<EventTag,EvtHandler>(evttag,method,handler->NextHandler.get(),id);
  }
  
   template<class EventTag,class EvtHandler>
   static void Unbind(){
        
        
        return;
    }
    //EventArg:This type is an Event...
 void ProcessEvent(const EventArg& event_arg){
     
      if(EventArg.GetClassName()==string("Event")){
          Event_Handler<EventArg,Class>* handler_iter;
     while(handler_iter!=nullptr){
     
     }
      }
      //Events are propagated to the current handler, if the parent_handler is even specified...
     
}      
  
};
