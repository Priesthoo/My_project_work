 #include<iostream>
using namespace std;
//Tutorial session...
int main(){	

 //Tutorial session 
print_nl(" values in the cicular list:");
Circular_list<int>clist={12,13,14,15,16,17,18,19,20};
clist.print_clist();

Node<int>*iter=clist.get_Nth_node_for_clist(1);
print_fn("the first element accessed by inserting 1 as an argument:");
print_value(iter->value);
cout<<endl;
print_fn("the second element accessed by inserting 2 as an argument");
iter=clist.get_Nth_node_for_clist(2);
print_value(iter->value);

}	