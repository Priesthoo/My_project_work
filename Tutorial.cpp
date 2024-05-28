#include<iostream>
#include"Hash_map.h"
using namespace std;
//Tutorial session...
int main(){	
String_map<string,string>smap={{"Hardwork","busy"},{"Hardwork","diligent"},{"Harwdork","industrious"},{"Hardwork","assiduous"},{"Hardwork","energetic"},{"Hardwork","employed"}};
smap.print_table();
cout<<endl;
cout<<"using string map as a synonyms dictionary"<<endl;
cout<<"words similar to hardwork:"<<endl;
smap.print_synonyms("Hardwork");
}