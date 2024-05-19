 #include<iostream>
using namespace std;
//Tutorial session...
int main(){	

 Circular_list<int>clist={12,13,14,15,16,17,18,19};
	print_nl("clist:");
	clist.print_clist();
	print_fn("first value of clist:");
	print_value(clist[0]);
	print_fn("second value of clist:");
	print_value(clist[1]);
}	