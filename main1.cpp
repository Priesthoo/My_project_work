#include<iostream>
#include<vector>
using namespace std;
int add_unique(const vector<int>& vec1){
    int var=0;
    if(vec1[0]==vec1[1]){
        var=vec1[0];
    }
    for(int i=1;i<vec1.size();i++){
        if(vec1[i-1]!=vec1[i]){
            int v=vec1[i];
            var+=v;
        }
    }
    return var;
}
int add_unique1(const vector<int>& vec){
     int var=0;
     int v=0;
   vector<int> vec1;
    for(int i=1;i<vec.size();i++){
       if(vec[i-1]==vec[i]){
           v=vec[i];
           continue;
       }
       if(vec[i-1]==v){
           continue;
       }
       vec1.push_back(vec[i-1]);
    }
    if(vec[vec.size()-1]!=vec[vec.size()-2]){
        vec1.push_back(vec[vec.size()-1]);
    }
    for(int i=0;i<vec1.size();i++){
        var+=vec1[i];
    }
    return var;
}

int main(int argc, char *argv[])
{ 
   vector<int>test={2,2,4,5,5,5,5,6,7,7};
   int j=add_unique1(test);
   cout<<j;
    // output:10....
	
}