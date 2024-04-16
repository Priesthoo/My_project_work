class  ColorRGBA {  
float red;
float green;
float blue;
float alpha;
public:
  ColorRGBA() = default; 
  ColorRGBA(float r, float g, float b, float a = 1.0F)  {   
  red = r; 
  green = g; 
  blue = b; 
  alpha = a; 
 }   
 ColorRGBA& operator *=(float s)  {   
 red *= s;
  green *= s; 
 blue *= s; 
 alpha *= s; 
  return (*this); 
 }  
  ColorRGBA& operator /=(float s)  {   
  s = 1.0F / s; 
  red *= s; 
  green *= s; 
  blue *= s; 
  alpha *= s; 
  return (*this); 
 }   
 ColorRGBA& operator +=(const ColorRGBA& c)  {  
  red += c.red; 
  green += c.green; 
  blue += c.blue; 
  alpha += c.alpha; 
  return *this;
 }   
 ColorRGBA& operator -=(const ColorRGBA& c)  {  
  red -= c.red; 
  green -= c.green; 
  blue -= c.blue; 
  alpha -= c.alpha; 
  return *this;
 }   
 ColorRGBA& operator *=(const ColorRGBA& c)  {   
 red *= c.red; 
 green *= c.green; 
 blue *= c.blue;        //+,-,/,*,=
 alpha *= c.alpha; 
 return *this;
 }
 ColorRGBA operator+(const ColorRGBA& c) const {
     ColorRGBA color1;
     color1.red=this->red+c.red;
     color1.blue=this->blue+c.blue;
     color1.green=this->green+c.green;
     color1.alpha=this->alpha+c.alpha;
     return color1;
  }
  ColorRGBA operator-(const ColorRGBA& c) const {
     ColorRGBA color1;
     color1.red=this->red-c.red;
     color1.blue=this->blue-c.blue;
     color1.green=this->green-c.green;
     color1.alpha=this->alpha-c.alpha;
     return color1;
  }
  ColorRGBA operator/(const float s) const {
     ColorRGBA color1;
     color1.red=this->red/s;
     color1.blue=this->blue/s;
     color1.green=this->green/s;
     color1.alpha=this->alpha/s;
     return color1;
  }
  ColorRGBA operator*(const float s) const {
     ColorRGBA color1;
     color1.red=this->red*s;
     color1.blue=this->blue*s;
     color1.green=this->green*s;
     color1.alpha=this->alpha*s;
     return color1;
  }
  ColorRGBA& operator=(const ColorRGBA& c)  {
     red=c.red;
     blue=c.blue;
     green=c.green;
     alpha=c.alpha;
     return *this;
  }

};
