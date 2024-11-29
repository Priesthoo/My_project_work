#include<vector>
#include<iostream>
#include<algorithm>
#include<chrono>
#include<memory>
//Implementation of bubble sort...
#include<utility>

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
//we use integer coordinate system to define points, So we have 
class Point_2D{
    private:
    int x;
    int y;
    public:
    Point_2D()=default;//if a Point_2D object is initialized with default 
    Point_2D(const int& _x,const int& _y){
        x=_x;
        y=_y;
    }
    Point_2D(const Point_2D& point){
        x=point.X();
        y=point.Y();
    }
    //This results in loss of precision.
    Point_2D(const float& _x,const float& _y){
        x=static_cast<int>(_x);
        y=static_cast<int>(_y);
     }
    int X() const {
        return x;
    }
    int Y() const {
        return y;
    }
    void sets_X(const int& _x){
        x=_x;
        return;
    }
    void sets_Y(const int& _y){
        y=_y;
        return;
    }
    void sets_both_x_and_y(const int& _x,const int& _y){
        sets_X(_x);
        sets_Y(_y);
        return;
    }
  bool operator==(const Point_2D& point) const{
       if(this->X()==point.X() &&(this->Y()==point.Y())){
           return true;
       }
 }
 bool operator>(const Point_2D& point) const {
     if(x>point.X() &&(y>point.Y())){
         return true;
     }
 }
bool operator<(const Point_2D& point) const {
     if(x<point.X() &&(y<point.Y())){
         return true;
     }
 }
 bool operator<=(const Point_2D& point) const {
     if(x<=point.X() &&(y<=point.Y())){
         return true;
     }
 }
 bool operator>=(const Point_2D& point) const {
     if(x>=point.X() &&(y>=point.Y())){
         return true;
     }
 }
 Point_2D& operator=(const Point_2D& point){
     *this={point};
     return *this;
 }
 bool is_default_initialized() const {
     if(*this==Point_2D()){
         return true;
     }
 }
 
 };
// It is a wonderful data structure
class QuadTree{
    private:
    Point_2D point_data;
    shared_ptr<QuadTree>North_East;
    shared_ptr<QuadTree>South_East;
    shared_ptr<QuadTree>South_West;
    shared_ptr<QuadTree>North_West;
    public:
    QuadTree()=default;
    Point_2D PointData() const{
        return point_data;
    }
    shared_ptr<QuadTree> NorthEast(){
        return North_East;
  }
  shared_ptr<QuadTree> SouthEast(){
      return South_East;
  }
  shared_ptr<QuadTree> SouthWest(){
      return South_West;
  }
  shared_ptr<QuadTree> NorthWest() const {
      return North_West;
  }
  bool contains_point(const Point_2D& point) const {
      if(point_data==point){
          return true;
      }
}
void sets_Point_data(const Point_2D& point){
    if(contains_point(point)){
        return;
    }
    point_data=point;
    return;
}

};

//Let's implement Merge sort......
//Implementing Merge sort requires three arrays,Two of the arrays are gotten by division of the input array into two.
template<class T>
void Implement_Merge_Sort(vector<T>& array, vector<T>& temp_array, int left_pos, int right_pos, const int& right_end){
    //This catches this error and handles it by returning to the caller of the function 
    if(array.size()==0){
        return;
        
    }
    // we need to get the temporary index for the temporary array.
    //The size of the array must be equal to avoid or prevent exceptions being thrown when size of temp_array is larger than that of the reference array
    
    if(temp_array.size()!=array.size()){
        return;
    }
    //Casting from type to type
    int temp_pos=static_cast<int>(left_pos);
    int left_end=static_cast<int>(right_pos-1);
    size_t no_of_element=static_cast<size_t>(right_end-left_pos+1);
    // This loop does one thing:
    //it loops through the elements and transfer ownership of resources,
    // Conditions are provided to execute the loop 
     while(left_pos<=left_end && (right_pos <= right_end)){
         if(array.at(left_pos)<=array.at(right_pos)){
             temp_array.at(temp_pos++)=std::move(array.at(left_pos++));
         }
         else{
             temp_array.at(temp_pos++)=std::move(array.at(right_pos++));      
        }
    }
    // This aspects check whether there are still elements that can be transferred
    while(left_pos<=left_end){
        temp_array.at(temp_pos++)=std::move(array.at(left_pos++));
    }
    while(right_pos<=right_end){
        temp_array.at(temp_pos++)=std::move(array.at(right_pos++));
    }
  //This also involves transfer of ownership from object passed by reference(to modify the properties ) to another object.
    for(int i=right_end;i>=0;i--){
        array.at(i)=std::move(temp_array.at(i));
    }
  }
  //This is the main loop....
  template<class T>
void Merge(vector<T>& array,vector<T>& temp_array, int left, int right){
 if(array.size()==0){
     return;
 }
 if(left<right){
     int center=(left+right)/2;
     Merge(array,temp_array,left,center);
     Merge(array,temp_array,center+1,right);
     Implement_Merge_Sort(array,temp_array,left,center+1,right);
 }

}
int main(int argc, char *argv[])
{  
    Point_2D point;
    if(point.is_default_initialized()){
        std::cout<<"it is default initialized"<<std::endl;
    }
    shared_ptr<int> sp(new int);
    *sp=12;
    std::cout<<*sp<<endl;
   vector<int>vector_int={12,11,4,56,7,8,0,2};
   vector<int>temp_array(static_cast<int>(vector_int.size()));
   Merge(vector_int,temp_array,0,vector_int.size()-1);
   for(const auto& ref: vector_int){
       std::cout<<ref<<endl;
   }
   
   
	
}