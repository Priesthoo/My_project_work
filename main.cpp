int main(int argc, char *argv[])
{    int val=67;
     Bnode<int>*bnode=new Bnode<int>;
     bnode->value=val;
     bnode->right=null;
     bnode->left=null;
     create_node(bnode,70);
     insert_new_node(bnode,17);
     insert_new_node(bnode,18);
      cout<<bnode->value<<endl;
     cout<<bnode->right->value<<endl;
     cout<<bnode->left->right->value;
                  /*
                                                                
                 67
                                                        /   \
                                                      /      \
                                                     /         \
           17          70                      
            \
             \
              18                            
                                            
                                              
  }