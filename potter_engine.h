#include"color.h"
#include"Matrix.h"
#include"Hash_map.h"
//OPENGL3D.... for  God's given game engine
using namespace HASH_MAP;
#define PT_ENGINE
#ifdef PT_ENGINE
typedef unsigned int pe_uint;
typedef signed int pe_int;
typedef short pe_short;
typedef char  pe_char;
typedef float pe_float;
typedef double pe_double;
#endif
enum class Event_type{
    IS_RUNNING,
    IS_DESTROYED,
    IS_WALKING,
    IS_HEALTH_0_25,
    IS_HEALTH_0_50,
    IS_HEALTH_0_75,
    IS_HEALTH_1_00,
    IS_COLLIDE,
    IS_NOT_COLLIDE,
    IS_ALIVE,
    IS_EXPLOSIVE
  };
#ifndef ANIMATION
#define ANIMATION
#endif
#ifdef ANIMATION
class Animation{
  }; 
#endif //animation

#ifndef PHYSICS
#define PHYSICS
#endif
#ifdef PHYSICS
class Physics{
    
};
#endif //physics
enum class Object_type{
    STATIC=0x0,
    DYNAMIC=0x01
};
enum LIGHT{
    POINT,//like the bulb
    DIRECTIONAL,//idea sunlight
    SPOT_LIGHT,//flash light
    AREA_LIGHT,//Real world simulation of light 
    INFINITE_LIGHT//it models the sun.
};
enum FRAME_BUFFER{
    STENCIL_BUFFER=1<<3,
    DEPTH_BUFFER=1<<5,
    COLOR_BUFFER=1<<7,
    DEPTH_BUFFER_AND_COLOR_BUFFER=DEPTH_BUFFER | COLOR_BUFFER
};
enum TEXTURE_MAP{
    SPECULAR_MAP_2D,
    COLOR_MAP_2D,      //reflection map
    EMISSION_MAP_2D,
    NORMAL_MAP_2D,
    PARALLAX_MAP_2D,
    PARALLAX_OCCLUSION_MAP_2D,
    BUMP_MAP_2D,
    DISPLACEMENT_MAP_2D,
    SHADOW_MAP_2D,
    LIGHT_MAP_2D,
    VOLUME_TEXTURE_MAP_3D,
    ALPHA_MAP_2D,
    HEIGHT_MAP_2D
};
enum PROCEDURAL_TEXTURE{
};
enum FALL_OFF{
    ATTENUATE_0,
    ATTENUATE_1,
    ATTENUATE_2
};
typedef Vector3d Position;
typedef Vector3d Direction;
typedef Vector3d Vertex;
using namespace std;
class Render_farm{
    private:
    float x;
    float y;
    public:
    Render_farm(float m, float n){
        x=m;
        y=n;
        }
  Render_farm(const float& m,const float& n){
       x=m;
       y=n;
       }
    Render_farm():x{},y{}{}
  };
enum PRIM{
    TRIANGLE,
    LINES,
    POINTS
};
enum SHAPE{
    SPHERE,
    DISC,
    TORUS,
    CYLINDER  
};
enum IMAGE_FORMAT_TYPE{
    JPEG,
    PNG,
    GIF,
    TIFF,
    PSD,
    EPS,
    BMP
};
   
struct Ray{
    public:
    Position pos;
    Direction dir;
    float time;
    bool is_intersect;
    float tmax;
};
void set_Ray_position(Ray*ray,const Position& pos1){
   ray->pos=pos1;
 }
 void set_Ray_direction(Ray*ray,const Direction& dir1){
     ray->dir=dir1;
 }
 void set_Ray_time(Ray*ray,const float time1){
     ray->time=time1;
 }
void set_Ray_intersection(Ray*ray,bool is_intersect1){
    ray->is_intersect=is_intersect1;
 }
 void set_tmax(Ray*ray,const float& tmax1){
     ray->tmax=tmax1;
 }
Position get_ray_pos(const Ray& ray){
    return ray.pos;
}
enum Material_property{
    DIFFUSE,  //for the color of the surface
    SPECULAR ,//for the specular highlight 
    ROUGHNESS,
    NORMAL_ORIENTATE,
    REFRACT_INDEX,
    SCATTER_INDEX,
    ABSORB_INDEX
};

//to model light interaction with material,we use multiplication..
//it handles light arriving at the point being shaded without interactioj with other objects...
//we characterise light by it's color and the spatial distribution in relation to the position and direction.'
class Light{
    private:
    ColorRGBA color;
    Position pos;
    Direction dir;
    public:
    Light():color{},pos{},dir{}{}
    Light(const ColorRGBA& rgba, const Position& pos1,const Direction& dir1){
        color=rgba;
        pos=pos1;
        dir=dir1;
    }
  Light(const Light& light){
      *this=light;
  }
  Light& operator=(const Light& light){
      color=light.color;
      pos=light.pos;
      dir=light.dir;
  }
 ColorRGBA& get_color(){
    return color;
    }    
  Position& get_pos(){
      return pos;
  }
  Direction& get_dir(){
      return dir;
  }
  ColorRGBA  get_color()const {
      return color;
  }
  
  void set_color(const ColorRGBA& color1){
      color=color1;
 }
  Position get_pos() const{
      return pos;
  }
  Direction get_dir() const{
      return dir;
  }
  void set_pos(const Position& pos1){
      pos=pos1;
  }
  void set_dir(const Direction& dir1){
      dir=dir1;
  }
  
};
typedef unsigned int world_int;
class Point_light:public Light{
    private:
    float attenuate;
    public:
    Point_light(const ColorRGBA& rgba,const Position& pos1,const Direction& dir1,float atten){
        this->get_color()=rgba;
        this->get_pos()=pos1;
        this->get_dir()=dir1;
        attenuate=atten;
     }
     Point_light():Light{},attenuate{}{}
     Point_light& operator=(const Point_light& point){
         this->get_color()=point.get_color();
         this->get_pos()=point.get_pos();
         this->get_dir()=point.get_dir();
         this->attenuate=point.attenuate;
         return *this;
     }
     static float get_dist_fall_off(const Point_light& point){
         return point.attenuate;
     }
 static float fall_off(const float& distance,const float& max_distance,FALL_OFF fall_off, const float& epsilon=0.001){
     if(fall_off==ATTENUATE_0){ return 0.001;}
     return 0.00123;
   }
};
class Spot_light:public Light{
    private:
    float dist_atten;
    float dir_atten;
    public:
    Spot_light():Light{},dist_atten{},dir_atten{}{}
    Spot_light(const ColorRGBA& rgba,const Position& pos1,const Direction& dir1,const float dist,const float dirt){
        this->get_color()=rgba;
        this->get_pos()=pos1;
        this->get_dir()=dir1;
        this->dist_atten=dist;
        this->dir_atten=dirt;
    }
    
};
struct Texture_3D{
    float x;
    float y;
    float z;
};
#ifndef TEXT_COORD
#define TEXT_COORD
struct Texture_2D{
    float x;
    float y;
};
#endif
#ifndef OBJECT_ATTRIBUTE
#define OBJECT_ATTRIBUTE
#endif
#ifdef OBJECT_ATTRIBUTE
struct Vertex_attribute{
    Vertex pos;
    Texture_2D text2d;
    Vertex normal;
    float weight;
    ColorRGBA color;
#ifdef TEXTURE_COORD_3D
     Texture_3D text3d;
#endif
 
};
#endif
//model transform consists of translation and rotation.
#ifndef OBJECT_VERTEX
#define OBJECT_VERTEX
#endif
#ifdef OBJECT_VERTEX
struct obj_vertex{
    Vertex_attribute*vertexattr;
    size_t count;
};
#endif //object vertices


struct Triangle{ //primitives mostly used by GPU hardware
   Vertex p0;
   Vertex p1;
   Vertex p2;
};
struct obj_triangle{
    Triangle* triang;
    size_t count;
};
struct Index_buffer{
    size_t idx0;
    size_t idx1;
    size_t idx2;
};
enum TEXTURE_PACK{
    TEXTURE_ATLAS_2D   //similar to texture_array_2d... 
};

/*
 They influence the points of a triangle, in what sense, They tend to determine points that fall within the triangle....
*/
struct Bary_weight{
    float b1;
    float b2;
    float b3;
};
void set_weight(Bary_weight*  bary_w1,const float& w1,const float& w2,const float& w3 ){
    bary_w1->b1=w1;
    bary_w1->b2=w2;
    bary_w1->b3=w3;
}
class PT_ENGINE Area_light{
    
};
enum BODY{
    RIGID_BODY,
    SOFT_BODY,
    DESTRUCT_BODY
};
enum DYNAMICS{
    RIGID_BODY_DYNAMICS,
    SOFT_BODY_DYNAMICS,
    DESTRUCT_BODY_DYNAMICS
};
enum COLLISION{
    RIGID_BODY_COLLISION,
    SOFT_BODY_COLLISION,
    DESTRUCT_BODY_COLLISION
};

enum MATERIAL_MODEL{
    LAMBERTIAN_MODEL,
    DIFFUSE_MODEL, // local subsurface scattering model
    SPECULAR_MODEL,//reflection model
    CARTOON_MODEL//mostly cartoon models
};
enum SHADER_TYPE{
    VERTEX_SHADER,
    FRAGMENT_SHADER,
    COMPUTE_SHADER,
    GEOMETRY_SHADER,
    TESSELLATION_SHADER
};
enum NDFs{
    ISOTROPIC_NDFS,
    ANISOTROPIC_NDFS
};
enum INTERSECTION{
};
#ifndef WORLD_STATE
#define WORLD_STATE
#endif
#ifndef OBJECT_STATE
#define OBJECT_STATE
#endif
#ifdef OBJECT_STATE
 struct Object{
 obj_vertex* Vertices;
 obj_triangle* triangles;
 Event_type event;
 BODY body;
 DYNAMICS dynamic;
 COLLISION collide;
 Animation* animate;
 Physics* physic;
};
#endif
#ifdef WORLD_STATE
  struct World{
      bool is_gravity;
      float gravity;
      world_int frame_buffer;
   };
#endif
#ifndef RENDERING
#define RENDERING
enum class RENDER{
    WORLD_RENDER,
    MATERIAL_RENDER,
    ANIMATE_RENDER,
    OBJECT_RENDER
};
#endif