#include<vector>
#include<iostream>
#include<algorithm>
//Implementation of bubble sort...

using namespace std;
template<class T>
void Bubble_Sort(vector<T>& Array){
    if(Array.size()==0){
        return;
    }
    for(int i=0;i<Array.size();i++){
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
//Implement different Partitons, Lomutos and Hoares partitions
template<class T>
int Implement_Hoares_Partition(vector<T>& array,const unsigned int& low,const unsigned int& high){
    
    int left=low-1;  //low-1, Reducing the first index by 1
    int right=high+1;//Increasing the second index by 1
   T pivot=array.at(low);  //we select the pivot as the lowest element
    while(true){
        left++;
        while(array.at(left)<pivot){
            left++;
        }
        right--;
        while(array.at(right)>pivot){
            right--;
        }
        if(left>=right){//This breaks the loop if left is equal or greater than right
            return right;
        }
       std::swap(array.at(left),array.at(right)); 
        
    }
}
//Function: It arranges the elements about a pivot, and returns the index of the pivot.
template<class T>
int Implement_Lomutos_Partition(vector<T>& Array,const unsigned int& low, const unsigned int& high){
    int pivot_index=high;
    int i=low-1;
    T pivot=Array.at(pivot_index);
    for(int j=low;j<high;j++){
        if(Array.at(j)<pivot){
            ++i;
            std::swap(Array.at(i),Array.at(j));
        }
    }
    std::swap(Array.at(i+1),Array.at(pivot_index));
    return (i+1);
 }

 template<class T>
 void Lomutos_Quick_Sort(vector<T>& Array,const size_t& low,const size_t& high){
     if(Array.size()==0){
         return;
     }
     if(low>=high){
         return;
     }
     int partition_index=Implement_Lomutos_Partition(Array,low,high);
     Lomutos_Quick_Sort(Array,low,partition_index-1);
     Lomutos_Quick_Sort(Array,partition_index+1,high);
     return;
 }
 
template<class T>
void Quick_Sort(vector<T>& array,const size_t& low, const size_t& high){
     if(array.size()==0){
         return;
     }
     if(low<high){
         int partition_index=Implement_Hoares_Partition(array,low,high);
         Quick_Sort(array,low,partition_index);
         Quick_Sort(array,partition_index+1,high);
     }
     return;
}


int main(int argc, char *argv[])
{
	vector<int> Array={5,1,9,4,14,7,5};
	Lomutos_Quick_Sort(Array,0,Array.size()-1);
	for(const auto& ref: Array){
	    cout<<ref<<endl;
	}
	
}