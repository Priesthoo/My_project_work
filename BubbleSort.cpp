#include<vector>
#include<iostream>
//Implementation of bubble sort...

using namespace std;
template<class T>
void Bubble_Sort(vector<T>& Array){
    if(Array.size()==0){
        return;
    }
    for(int i=0;i<Array.size()-1;i++){
        unsigned int k=0;
        for(int j=1;j<Array.size()-i;j++){
       if(Array.at(j-1)>Array.at(j)){
             T value=Array.at(j-1);
              Array.at(j-1)=Array.at(j);
               Array.at(j)=value;
                k=1;
                }
        }
        if(k==0){
            return;
        }
   }
   return;
}

int main(int argc, char *argv[])
{
	vector<int> Array={5,1,9,4,14,7,5};
	Bubble_Sort(Array);
	for(const auto& element: Array){
	    cout<<element<<endl;
	}
	
	
}