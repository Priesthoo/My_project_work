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
int main(int argc, char *argv[])
{
	size_t sz=IS_PATH;
	cout<<sz<<endl;
	int handle=open("file.txt",O_RDWR|O_APPEND);//opening file for reading and writing..
	void*buff=nullptr;
	unsigned long word=0;
	ssize_t sz1=read(handle,&word,4);
	ssize_t sz3=read(handle,&word,4);
	File_offset* file_off=new File_offset;
	file_off->offset=lseek(handle,(off_t)0,SEEK_CUR);
	cout<<"File position after read operation:"<<file_off->offset<<endl;
#ifndef CONST_CHAR_PTR
#define CONST_CHAR_PTR
 const char*str="Hello my friend";
 #endif
 
	ssize_t sz2=write(handle,str,strlen(str));
	cout<<"Write bytes :"<<sz2<<endl;
	cout<<"Read bytes:"<<sz1<<endl;
	File_offset* file_off1=new File_offset;
	file_off1->offset=lseek(handle,(off_t)0,SEEK_CUR);
	cout<<"File position after write operation:"<<file_off1->offset<<endl;
	
	delete file_off1;
	delete file_off;
}