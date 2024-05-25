 #include<iostream>
using namespace std;
//Tutorial session...
int main(){	
Node<int>*node=new Node<int>;
    init(node,{12,14,15,17,18,19,20,21,22,34,56,78,68});
    Dlist<int> dlist={node};
    cout<<"values of double linked list:"<<endl;
    dlist.print_dlist_forward();
    Node<int>*nNode=dlist.Get_nth_node(5);
    print(nNode);
    cout<<endl;
    cout<<"Inserting 67 after the 5th element:"<<endl;
    dlist.insert_after_pos(nNode,67);
    dlist.print_dlist_forward();
    cout<<endl;
    cout<<"inserting 59 before the 5th element:"<<endl;
    dlist.insert_before_pos(nNode,59);
    dlist.print_dlist_forward();
}