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



#ifdef LIMIT
#include<limits.h>
#endif
#ifndef FILE_OPERATION
#define FILE_OPERATION
class File_ops{
    public:
    FILE* file_stream;
    size_t no_of_bytes;
    const char*mode;
    public:
    File_ops():file_stream{NULL},no_of_bytes{},mode{NULL}{}
  };
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

int main(int argc, char *argv[])
{
	/*
	As we read from the open file(stream), the offset of the file is updated....
	*/
	FILE* file_op;
	 file_op=fopen("file.txt","r");
	 char ch[10];
	char*str=(char*)fread_string_from_stream(ch,10,"file.txt");
	cout<<str[0]<<endl;
	 
	 
	 
	 
	 
	 
	/*
	Reading arbitrary length of string from stream;
	
	*/
	
	
}