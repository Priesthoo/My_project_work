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
       if(ob==nullptr){
           return;
       }
       
       orig_object=ob;
       return;
   }
    EventType GetType() const{
        return Type;
    }
    long GetId() const{
        return id;
    }
    Object* GetOrigin_Object() const{ // when comparing,we will compare addresses .
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
class CustomEvent:public Event{
    public:
    CustomEvent(EventType type,long id):Event(type,id){
        SetClassName(string("Custom Event"));
    }
};

 template<class Class>
 using Classmethod=void(Class::*)(Event& arg);
 
//This maps the Eventtype, Event and the handler together..,Note EventArg represents the event, EventTag represents the type of event.
template<class Class>
class Event_Functor_Mapper{
    
    public:
    Event event;
    Classmethod<Class>Method;
    Event_Functor_Mapper(){
        
    }
    Event_Functor_Mapper(const Event& p_event,Classmethod<Class> method){
        event=p_event;
        Method=method;
        
    }
    Event_Functor_Mapper(const Event_Functor_Mapper& mapper){
       this->event=mapper.event;
       this->Method=mapper.Method;
    }
    
};
template<class Class>  //Forward Declaration
class EventHandler;

template<class Class> //Event handler list....
using Event_Handler_List=list<EventHandler<Class>>;
/*
Event Handler will handle events, it Maps Event to member function pointers
Criteria to convert from one member function pointer to another function pointer...
1).A derived class must derive from a base class. By that, We can convert from  derived member function pointer to Base memeber function pointer and vice versa....



*/
namespace Function{
    /*
   This is used when a class provides it's callback function and but it is another class that provides the Event_Handler_List....
    
    
    */
    template<class EventTag,class Class, class Another_Class,class OriginObject>
    void Bind(const EventTag& evttag,Classmethod<Another_Class> method_1,Event_Handler_List<Class>* handler,const long& id,OriginObject* object){
        if(handler==nullptr){
            std::cout<<"Handler is empty,To solve this,Either use a custom allocator or alocate from the heap directly,or use smart pointers"<<std::endl;
            return;
        }
        EventHandler<Class> evthandler;
        Event event1(evttag,id);
        if(evthandler.Handler.get()==nullptr){
            evthandler.Handler.reset(new Event_Functor_Mapper<Class>);
        }
        evthandler.Handler->event=event1;
        evthandler.Handler->event.SetOrigin_Object(object);
        evthandler.Handler->Method=static_cast<Classmethod<Class>>(method_1);
        handler->push_back(evthandler);
        return;
       }
  /*
  This is used when a class provides both it's callback function and Event_Handler_List.........
   
  */
   template<class EventTag,class Class,class OriginObject>
   void Bind_Method(const EventTag& evttag, Classmethod<Class> method,Event_Handler_List<Class>*handler,const long& id,OriginObject* object){
       if(handler==nullptr){
           std::cout<<"Handler is empty,To solve this,Either use a custom allocator or alocate from the heap directly,or use smart pointers"<<std::endl;
            return;
        }
       EventHandler<Class> evthandler;
       Event event1(evttag,id);
       if(evthandler.Handler.get()==nullptr){
            evthandler.Handler.reset(new Event_Functor_Mapper<Class>);
        }
        evthandler.Handler->event=event1;
        evthandler.Handler->event.SetOrigin_Object(object);
        evthandler.Handler->Method=method;
        handler->push_back(evthandler);
        return;
   }
   
   //This is used when we have class for event handling and another class for Event_handlet_list....
  template<class EventTag,class Class,class Another_Class,class Origin_Object>
  void Bind_Method(const EventTag& evttag,Classmethod<Class> method,Event_Handler_List<Another_Class>*handler,const long& id,Origin_Object* object){
       if(handler==nullptr){
           std::cout<<"Handler is empty,To solve this,Either use a custom allocator or alocate from the heap directly,or use smart pointers"<<std::endl;
            return;
        }
        EventHandler<Another_Class>evthandler;
        Event event1(evttag,id);
        if(evthandler.Handler.get()==nullptr){
            evthandler.Handler.reset(new Event_Functor_Mapper<Another_Class>);
            
        }
        evthandler.Handler->event=event1;
        evthandler.Handler->event.SetOrigin_Object(object);
        evthandler.Handler->Method=static_cast<Classmethod<Another_Class>>(method);
        handler->push_back(evthandler);
        return;
  }
   
       
 //This unbinds the Event and the call back function(class Method) from the event handler
bool Unbind();

   template<class Class,class Another_Class>
   bool ProcessEvent(Event_Handler_List<Class>* handler,Event& event_arg){
       if(handler==nullptr){
           std::cout<<"Event_Handler_List  is empty, We can not process any event, Attach an Event_Handler_List to the pointer variable"<<std::endl;
       }
       for(const auto& Evthandler:*handler){
           Event arg=Evthandler.Handler->event;
           if(arg.GetClassName()==event_arg.GetClassName() &&(arg.GetOrigin_Object()==event_arg.GetOrigin_Object())&& (arg.GetType()==event_arg.GetType())&& (arg.GetId()==event_arg.GetId())){
                Classmethod<Another_Class>  method=static_cast<Classmethod<Another_Class>>(Evthandler.Handler->Method);
                Another_Class instance;
                (instance.*method)(event_arg);
                return true;
     }
       }
       return false;
   }
 
}

template<class Class>
class EventHandler:public Object{
    public:
    unique_ptr<Event_Functor_Mapper<Class>>Handler;
    long id;
    EventHandler(){
        Handler.reset(new Event_Functor_Mapper<Class>);
    }
    EventHandler(unique_ptr<Event_Functor_Mapper<Class>>p_handler,const long& p_id){
        Handler=std::move(p_handler);
        id=p_id;
    }
    EventHandler(const EventHandler& handler){
        Handler=std::move(handler.Handler);
        id=handler.id;
    }
    void SetId(const long& p_id){
        id=p_id;
        return;
    }
    void SetHandler(unique_ptr<Event_Functor_Mapper<Class> >ptr){
        Handler=std::move(ptr);
        return;
    }
    
template<class EventTag,class AnotherClass,class OriginObject>
void Bind(const EventTag& evttag, Classmethod<AnotherClass>method_1,Event_Handler_List<Class>* handler,const long& id,OriginObject* obj){
     Function::Bind<EventTag,Class,AnotherClass,OriginObject>(evttag,method_1,handler,id,obj);
}
template<class EventTag,class OriginObject>
void Bind(const EventTag& evttag,Classmethod<Class>method,Event_Handler_List<Class>* handler,const long& id,OriginObject* object){
    Function::Bind_Method<EventTag,Class,OriginObject>(evttag,method,handler,id,object);
}

};
