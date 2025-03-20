#include<iostream>
//To illustrate functions pointers, can we allocate memory on the heap to actually execute the functions
typedef void (*Func_ptr)(const int&);
void Print_value(const int& value){
    std::cout<<value<<std::endl;
    return;
}

int main(int argc, char *argv[])
{
	Func_ptr* func=new Func_ptr;
	*func=Print_value;
 static_cast<Func_ptr>(*func)(15);
	

	
}