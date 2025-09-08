#include<iostream>
using namespace std;
class Printer{
	public:
	Printer(){
	}
virtual void Print(){
	std::cout<<"Print me"<<std::endl;
	}
};
class ColourPrinter:public Printer{
	public:
	ColourPrinter(){
		
	}
	void Print() override{
		Printer::Print();
		std::cout<<"Color printing"<<std::endl;
	}
};
int main(){
	Printer* print=new ColourPrinter();
	print->Print();
}