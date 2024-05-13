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

int main(int argc, char *argv[])
{ 
   vector<int>test={2,2,4,5,5,5,5,6,7,7};
   int j=add_unique(test);
   cout<<j;
    // output:24...
	
}