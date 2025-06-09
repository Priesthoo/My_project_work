 #include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
enum FILE_STREAM_STATE{
    FILE_STREAM_STATE_OK=7,
    FILE_STREAM_STATE_BAD=6,
    FILE_STREAM_STATE_FAIL=8,
    FILE_STREAM_STATE_EOF=10,
    FILE_STREAM_STATE_INVALID=2
};
using namespace std;
struct IntegerPoint{
    int x;
    int y;
};
class RealPoint{
    float r_x;
    float r_y;
    public:
    RealPoint(){
    }
    RealPoint(const float& r_x_1,const float& r_x_2){
        r_x=r_x_1;
        r_y=r_x_2;
    }
    RealPoint(const RealPoint& point){
        r_x=point.r_x;
        r_y=point.r_y;
    }
    RealPoint& operator=(const RealPoint& point){
        r_x=point.r_x;
        r_y=point.r_y;
        return *this;
    }
    float GetX() const{
        return r_x;
    }
    float& GetX(){
        return r_x;
    }
    float GetY() const{
        return r_y;
    }
    float& GetY(){
        return r_y;
    }
    
};

class Line{
    RealPoint StartPoint;
    RealPoint EndPoint;
  public:
  Line()=default;
  Line(const RealPoint& sp, const RealPoint& ep){
      StartPoint=sp;
      EndPoint=ep;
  }
  Line(const Line& line){
      StartPoint=line.StartPoint;
      EndPoint=line.EndPoint;
      
  }
  Line& operator=(const Line& l){
      StartPoint=l.StartPoint;
      EndPoint=l.EndPoint;
      return *this;
  }
  RealPoint GetStartPoint() const{
      return StartPoint;
  }
  RealPoint& GetStartPoint(){
      return StartPoint;
  }
  RealPoint GetEndPoint() const{
      return EndPoint;
  }
  RealPoint& GetEndPoint(){
      return EndPoint;
  }
  
};
class Circle;
class Error; //This holds a variable that will indicate if an error has happened 
//Opens file for writing and storing changes....
class FileWriter{
   void WriteLineToStream(ofstream& openfile,const Line& line){
       openfile<<"LINE:\n";
       openfile<<"StartPoint:"<<"("<<line.GetStartPoint().GetX()<<","<<line.GetStartPoint().GetY()<<")\n";
       openfile<<"EndPoint:"<<"("<<line.GetEndPoint().GetX()<<","<<line.GetEndPoint().GetY()<<")\n";
       openfile<<"\n";
   }
   bool CheckForValidity(const string& filename){
       ofstream openfile(filename);
       if(openfile.is_open()){
           return true;
       }
       return false;
   }
 int GetStateOfFile(const ofstream& openstream){
     if(openstream.eof()){
         return static_cast<int>(FILE_STREAM_STATE_EOF);
     }
     if(openstream.bad()){
         return static_cast<int>(FILE_STREAM_STATE_BAD);
     }
     if(openstream.fail()){
         return static_cast<int>(FILE_STREAM_STATE_FAIL);
     }
     if(openstream.good()){
         return static_cast<int>(FILE_STREAM_STATE_OK);
     }
     if(openstream.bad() && openstream.eof()){
         return static_cast<int>(FILE_STREAM_STATE_BAD|FILE_STREAM_STATE_EOF);
     }
     if(openstream.fail() && openstream.eof()){
         return static_cast<int>(FILE_STREAM_STATE_FAIL|FILE_STREAM_STATE_EOF);
     }
     if(openstream.bad() && openstream.fail()){
         return static_cast<int>(FILE_STREAM_STATE_BAD|FILE_STREAM_STATE_FAIL);
     }
     if(openstream.eof() && openstream.bad() && openstream.fail()){
         return static_cast<int> (FILE_STREAM_STATE_EOF|FILE_STREAM_STATE_BAD|FILE_STREAM_STATE_FAIL);
     }
     
     return static_cast<int>(FILE_STREAM_STATE_INVALID);
 }
  public:
  
  FileWriter(const string& filename,const std::vector<Line>& lines){
      ofstream openfile(filename);
      bool Check=CheckForValidity(filename);
      if(Check){
          if(GetStateOfFile(openfile) & FILE_STREAM_STATE_OK){
              openfile<<"PSA file Format \n";
              if(!lines.empty()){
                  for(const auto line:lines){
                      WriteLineToStream(openfile,line);
                  }
              }
          }
          openfile.close();
      }
      
      
  }
    
};
//PerLineBuffer....
//FileReader will read the contents of .PSA file Format and Convert it to meaningful data
class FileReader{
 //This is not the same as Drawing Line, We are talking about lines in file context, Data is arranged per line
 //openstream is an opened file stream(the file has been opened already)
 void ReadFilePerLine(ifstream& openstream,std::vector<Line>& lines){
     char ch[90]={};
     Line ReadLine;
     
     while(openstream.getline(ch,70)){
        
        std::cout<<ch<<std::endl; //This is PSA file format...
        string str=string(ch);
        
         unsigned int break_point;
         if(str.substr(0,10)==string("StartPoint")){
                string value_string;
               for(int i=12;i<str.size();i++){
                   if(str[i]==','){
                       break_point=i;
                       break;
                   }
                   value_string.push_back(str[i]);
         }
               ReadLine.GetStartPoint().GetX()=stof(value_string);
               value_string.clear();
               for(int i=(break_point+1);i<str.size();i++){
                   if(str[i]==')'){
                       break;
                   }
                   value_string.push_back(str[i]);
               }
               ReadLine.GetStartPoint().GetY()=stof(value_string);
         }
         if(str.substr(0,8)==string("EndPoint")){
             string value_string;
             for(int i=10;i<str.size();i++){
                 if(str[i]==','){
                     break_point=i;
                     break;
                 }
                 value_string.push_back(str[i]);
             }
             ReadLine.GetEndPoint().GetX()=stof(value_string);
             value_string.clear();
             for(int i=(break_point+1);i<str.size();i++){
                 if(str[i]==')'){
                     break;
                 }
                 value_string.push_back(str[i]);
             }
             ReadLine.GetEndPoint().GetY()=stof(value_string);
             lines.push_back(ReadLine);
         }
         
        continue;
         return;
     }
 }
  
     
     int GetStateOfFile(const ifstream& openstream){
     if(openstream.eof()){
         return static_cast<int>(FILE_STREAM_STATE_EOF);
     }
     if(openstream.bad()){
         return static_cast<int>(FILE_STREAM_STATE_BAD);
     }
     if(openstream.fail()){
         return static_cast<int>(FILE_STREAM_STATE_FAIL);
     }
     if(openstream.good()){
         return static_cast<int>(FILE_STREAM_STATE_OK);
     }
     if(openstream.bad() && openstream.eof()){
         return static_cast<int>(FILE_STREAM_STATE_BAD|FILE_STREAM_STATE_EOF);
     }
     if(openstream.fail() && openstream.eof()){
         return static_cast<int>(FILE_STREAM_STATE_FAIL|FILE_STREAM_STATE_EOF);
     }
     if(openstream.bad() && openstream.fail()){
         return static_cast<int>(FILE_STREAM_STATE_BAD|FILE_STREAM_STATE_FAIL);
     }
     if(openstream.eof() && openstream.bad() && openstream.fail()){
         return static_cast<int> (FILE_STREAM_STATE_EOF|FILE_STREAM_STATE_BAD|FILE_STREAM_STATE_FAIL);
     }
     
     return static_cast<int>(FILE_STREAM_STATE_INVALID);
 }   
 public:
 FileReader(const string& filename,std::vector<Line>&lines){
       if(!lines.empty()){
           lines.clear();   //This is used when we are suing the same object for both reading and writing....
       }
    ifstream openstream(filename);
    if(openstream.is_open()){
          if(GetStateOfFile(openstream) & FILE_STREAM_STATE_OK){
              ReadFilePerLine(openstream,lines);
          }
    }
        
     openstream.close(); 
        
    }
    
    
    
};

int main(int argc, char *argv[])
{  std::vector<Line>lines;
   Line line(RealPoint(5.0f,6.0f),RealPoint(10.0f,13.0f));
   Line line_1(RealPoint(8.0f,9.0f),RealPoint(5.0f,20.0f));
   Line line_2(RealPoint(6.0f,45.0f),RealPoint(67.0f,56.0f));
   
   Line line_3(RealPoint(6.5f,5.0f),RealPoint(7.0f,6.7f));
   lines.push_back(line);
   lines.push_back(line_1);
   lines.push_back(line_2);
   lines.push_back(line_3);
   
   FileWriter filewriter(string("File.PSA"),lines);
   
   std::cout<<"Start writing To File"<<std::endl;
   
   FileReader filereader(string("File.PSA"),lines);
   std::cout<<"End of writing to file"<<std::endl;
   std::cout<<"\n";
   //Since we know that at this point, The lines won't be empty....'
   std::cout<<"Start of Reading from file"<<std::endl;
   if(lines.empty()){
       std::cout<<"collections of lines is empty"<<std::endl;
   }
	std::cout<<std::dec;//Formatting the stream to print out decimals
	for(const auto& ref: lines){
	    std::cout<<"StartPoint:"<<"("<<ref.GetStartPoint().GetX()<<","<<ref.GetStartPoint().GetY()<<")"<<std::endl;
	    std::cout<<"EndPoint:"<<"("<<ref.GetEndPoint().GetX()<<","<<ref.GetEndPoint().GetY()<<")"<<std::endl;
	    std::cout<<"\n";
	}
	std::cout<<"End of Reading from file"<<std::endl;
}