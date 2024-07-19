#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include<iostream>
#include<cctype>
using namespace std;
#define PROGRAM

#ifndef READ_AND_WRITE
#define READ_AND_WRITE
#include<unistd.h>
#endif
#define CPP 12

#ifdef PROGRAM
#if CPP
#define null_ptr nullptr
#else
#define null_ptr NULL
#endif
#endif 

#ifndef COLLECTION
#define COLLECTION
#include"char_collection.h"
#endif



#ifndef MY_FILE
#define MY_FILE 10
#endif // my file....

#ifdef MY_FILE
#if MY_FILE>9
#define IS_PATH 0x79
#else
#define IS_PATH 0x55
#endif //for if
#endif //MY_FILE

// for stream of characters 
#ifndef STDIN 
#define STDIN 0
#endif

#ifndef STDOUT
#define STDOUT 1
#endif

#ifndef OFFSET
#define OFFSET
class File_offset{
    public:
    off_t offset;
    File_offset()=default;
#ifndef OFFSET_OPERATOR
#define OFFSET_OPERATOR
File_offset& operator=(off_t value){
    offset=value;
    return *this;
}
#endif
};
#endif
#ifndef FILE_SIZE
#define FILE_SIZE
class File_Size{
    public:
    ssize_t size;
    
    
};
#endif
#ifndef TRUNCATE
#define TRUNCATE
#endif

#ifndef STANDARD_INPUT_AND_OUTPUT
#define STANDARD_INPUT_AND_OUTPUT
#include<stdio.h>
#endif
#ifndef LIMIT
#define LIMIT
#endif



#ifndef NO_OF_BYTES
#define NO_OF_BYTES
size_t no_of_file_bytes(const char*ch){
    FILE *file=fopen(ch,"r");
    size_t c=0;
    int c1=fgetc(file);
    while(c1!=EOF){
        ++c;
        c1=fgetc(file);
    }
    return c;
}
#endif

FILE *return_stream(FILE* file){
    return file;
}

#define INVALID_STREAM_POS -1

#ifndef FILE_PTR
#define File_ptr  FILE*
#endif

#ifndef STREAM_POS_TYPE
#define STREAM_POS_TYPE
typedef long stream_pos;
#endif


#ifdef LIMIT
#include<limits.h>
#endif
#ifndef FILE_OPERATION
#define FILE_OPERATION
namespace File_Operation{
class File_ops{
    private:
    void rewind();
    void get_curr_stream_position();
    void unchanged_read();
    public:
    FILE* file_stream;
    const char* file_name;
    size_t no_of_bytes;
    stream_pos curr_pos;
    int file_descriptor;
     public:
    File_ops():file_stream{NULL},file_name{null_ptr},no_of_bytes{},curr_pos{}{}
     File_ops(File_ptr stream,const char* file_name1){
        file_stream=stream;
        file_name=file_name1;
        no_of_bytes=no_of_file_bytes(file_name);
        curr_pos=fseek(file_stream,0,SEEK_CUR);
        file_descriptor=fileno(file_stream);
    }
    ~File_ops(){
        file_stream=null_ptr;
        file_name=null_ptr;
        no_of_bytes=0;
        curr_pos=0;
        file_descriptor=-1;
    }
  };
}
#endif

void*fread_string_from_stream(char*str,size_t byte,const char*ch){
    if(str==null_ptr){
        return null_ptr;
    }
    if(byte>no_of_file_bytes(ch)){
        return null_ptr;
}
  FILE* file_stream=fopen(ch,"r");
  int c=0;
  for(int i=0;i<byte;i++){
      c=fgetc(file_stream);
      str[i]=c;
  }
  return str;
}
/*
 For file operation, File position is important, i must implement an interface that describes the file position
 int rewind_stream(FILE*stream);
 void get_curr_stream_pos(FILE*stream);
 
 
*/


int main(int argc, char *argv[])
{
	/*
	As we read from the open file(stream), the offset of the file is updated....
	*/
	FILE* file_op;
	 file_op=fopen("file.txt","r");
	 char ch[10];
	char*str=(char*)fread_string_from_stream(ch,10,"file.txt");
	for(int i=0;i<10;i++){
	    cout<<str[i];
	}
	cout<<endl;
	int get=fgetc(file_op);
	int h=fseek(file_op,0,SEEK_SET);
    cout<<sizeof(off_t)<<endl;
    fflush(file_op);
    int fd=fileno(file_op);
    cout<<fd<<endl;
    auto mseek=lseek(fd,0,SEEK_CUR);
    cout<<mseek<<endl;
	File_Operation::File_ops My_file_mod={file_op,"file.txt"};
	const char* h1={"hello who is this, how are you doing"};
	cout<<strlen(My_file_mod.file_name)<<endl;
	cout<<sizeof(File_ptr)<<endl;
	cout<<"number of bytes: "<<My_file_mod.no_of_bytes<<endl;
	cout<<"current stream position:"<<My_file_mod.curr_pos<<endl;
	cout<<sizeof(File_Operation::File_ops)<<endl;
	
	 
	 
	 
	 
	 
	/*
	Reading arbitrary length of string from stream;
	
	*/
	
	
}