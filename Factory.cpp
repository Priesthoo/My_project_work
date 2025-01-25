//A class that provides a copy of a particular object 
template<class T>
class Clone{
    public:
    T clone() {
        return static_cast<T*>(this)->make_clone();
    }
};
//The Factory Method.
class Mechanics: public Clone<Mechanics>{
    private:
    bool is_dynamic;
    bool is_static;
    int physic_mode;
    Mechanics(bool is_physic_1,bool is_physic_2, int mode){
        is_dynamic=is_physic_1;
        is_static=is_physic_2;
        physic_mode=mode;
   }
   Mechanics(const Mechanics& mechanic){
       this->is_dynamic=mechanic.is_dynamic;
       this->is_static=mechanic.is_static;
       this->physic_mode=mechanic.physic_mode;
   }
   
    public:
    friend class Mechanics_Initializer;
    Mechanics& operator=(const Mechanics& mechanic){
        *this={mechanic};
        return*this;
    }
    Mechanics make_clone() {
        return *this;
    }
    
};
class Mechanics_Initializer{
    public:
    static Mechanics New_Object(const bool& physic1,const bool& physic2,int mode){
    return Mechanics(physic1,physic2,mode);
    }
};