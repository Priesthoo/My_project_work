#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{    
  vector<string>game(9," ");
  unsigned int trial=9;
  string ch;
  unsigned int c=0;
  unsigned int d=0;
  
  do{
      cout<<"enter value  from 0 to 8:"<<endl;
      int i;
 
      cin>>i;
      if(game.at(i)=="X" or game.at(i)=="O"){
          cout<<i<<" is taken"<<endl;
          cout<<"take another trial"<<endl;
         }
    
        else{ 
           cout<<"1).Player_one(X)"<<endl;
             cout<<"2).Player_two(O)"<<endl;
             cout<<"enter player:";
             unsigned int a;
             string c1;
             cin>>a;
             if(a==1){
                c1="X"; 
             }
             else if(a==2){
                 c1="O";
             }
             if(ch==c1 and c1=="X"){
                 cout<<"let player_two enter "<<endl;
             }
             else if(ch==c1 and c1=="O"){
                 cout<<"let player_one enter "<<endl;
             }
             else{
             if(a==1){
                 ch="X";
                 game.at(i)="X";
                
                 }
             else if(a==2){
                ch="O";
                game.at(i)="O";
                
                }
             --trial;
             }
         }
         }
  
  while(trial!=0);
 for(int i=0;i<9;i++){
     cout<<game.at(i)<<"   "<<"|";
     if((i+1)%3==0){
         cout<<endl;
         
     }
 }
}