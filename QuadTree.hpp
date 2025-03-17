#include<iostream>
#include<memory>
#include<cmath>
typedef float Float;
typedef double Double;
typedef int Int;
using namespace std;
//Octree that has (S^3-1)/7
template<class T>
class Point{
   private:
   T x;
   T y;
   public:
   Point()=default;
   Point(const T& _x,const T& _y):x{_x},y{_y}{}
   Point(const Point<T>& point){
       this->X()=point.X();
       this->Y()=point.Y();
   }
    T X() const{
        return x;
    }
    T Y() const {
        return y;
    }
    T& X(){
        return x;
    }
    T& Y() {
        return y;
    }
    Point& operator=(const Point<T>& point){
        this->X()=point.X();
        this->Y()=point.Y();
        return *this;
    }
    void setToNull(){
        x=T{};
        y=T{};
    }
    
    bool isSetToNull() const{
        if(X()==T{} &&(Y()==T{})){
            return true;
        }
    }
 Point operator-(const Point<T>& point){
     return Point(X()-point.X(),Y()-point.Y());
 } //This returns the absolute values after subtraction, Negative values will be converted to positive values, Positive values will still be positive 
  Point obtainAbsolute(){
      Point<T>  abspoint=Point(std::abs(X()),std::abs(Y()));
      return abspoint;
  }

};

class OctreeNode{
};
class Octree{
    
};
template<class T>
class QuadTree{
    private:
    shared_ptr<Point<T>> data;
    Point<float> TopLeft_point;
    Point<float> BottomRight_point;
    shared_ptr<QuadTree<T>> North_West;
    shared_ptr<QuadTree<T>> North_East;
    shared_ptr<QuadTree<T>>South_West;
    shared_ptr<QuadTree<T>> South_East;
    bool is_Point_in_Boundary(const Point<T>& point) const{
         if(point.X() >TopLeft_point.X() &&(point.Y() <BottomRight_point.X()) &&(point.Y() >TopLeft_point.Y())&&(point.Y()<BottomRight_point.Y())){
             return true;
             }    
    }
    public: 
    QuadTree(){
        data.reset(new Point<T>());
        TopLeft_point.setToNull();
        BottomRight_point.setToNull();
    }
    QuadTree(const Point<float>& first_min_point,const Point<float>& first_max_point){
        if(!first_max_point.isSetToNull() &&(!first_min_point.isSetToNull())){
            BottomRight_point=first_max_point;
            TopLeft_point=first_min_point;
            data.reset(new Point<T>());
        }
        
    }
    /*    
             
                  (TopLeft_point.x,TopLeft_point.y)-----------------------------------------------------------
      
                                                  |
                                                  |
                                                  |
                                                  
                                              
                                                                                                                                                                (BottomRight_point.x,BottomRight_point.y)
    
    
    */
    
    
    
    void insert_a_point(Point<T>* point){
        if(point==NULL){
            return;
        }
        if(!is_Point_in_Boundary(*point)){
            return;
        }
      Point<float> abspoint;
      abspoint=(BottomRight_point-TopLeft_point).obtainAbsolute();
      if(abspoint.X()<=1 &&(abspoint.Y()<=1)){
          if(data.get()==NULL){
          data->X()=point->X();
          data->Y()=point->Y();
          return;
          }
      }
      if((TopLeft_point.X()+BottomRight_point.X()/2)>=point->X()){
          //This is North_West
          if((TopLeft_point.Y()+BottomRight_point.Y()/2 )>=point->Y()){
              if(North_West.get()==NULL){
              North_West.reset(new QuadTree<T>(Point(TopLeft_point.X(),TopLeft_point.Y()),Point(TopLeft_point.X()+BottomRight_point.X()/2,TopLeft_point.Y()+BottomRight_point.Y()/2)));
              North_West->insert_a_point(point);
             }
          }
          //This is south west
          else{
             if(South_West.get()==NULL){
             South_West.reset(new QuadTree<T>(Point(TopLeft_point.X(),TopLeft_point.Y()+BottomRight_point.Y()/2),Point(TopLeft_point.X()+BottomRight_point.X()/2,BottomRight_point.Y())));
                South_West->insert_a_point(point);
             }
          }
      }
      else{
         if((TopLeft_point.Y()+BottomRight_point.Y()/2)>=point->Y()){
              //North_East
              if(North_East.get()==NULL){
                  North_East.reset(new QuadTree<T>(Point(TopLeft_point.X()+BottomRight_point.X()/2,TopLeft_point.Y()+BottomRight_point.Y()/2),Point(BottomRight_point.X(),TopLeft_point.Y()+BottomRight_point.Y()/2)));
                 North_East->insert_a_point(point);
              }
   }
          else{
              //This is South_East
              if(South_East.get()==NULL){
                  South_East.reset(new QuadTree<T>(Point(TopLeft_point.X()+BottomRight_point.X()/2,TopLeft_point.Y()+BottomRight_point.Y()/2),Point(BottomRight_point.X(),BottomRight_point.Y())));
                  South_East->insert_a_point(point);
              }
          }
    }
    }
   
};

int main()
{
  QuadTree<float> quad_tree(Point(-12.0f,-12.0f),Point(60.0f,60.0f));
  Point<float> point_1;
  point_1=Point(3.0f,4.0f);
  quad_tree.insert_a_point(&point_1);
   
   
   }