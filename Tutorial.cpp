 #include<iostream>
using namespace std;
//Tutorial session...
int main(){	

 cout<<"Printing values::"<<endl;
Map<string,int> mine={{"string",17},{"string",67},{"int",78}}; 

mine.print_map(); //print values in mine.
cout<<endl;

cout<<"After adding new elements by array:"<<endl;
/*adding elements by subscript operator,I overloaded it to work that way. The more u add, The more the Map object expands.
*/
 mine["float"]=5;
 mine["day"]=56;
 mine["University"]=68;
 mine["Great"]=700;
 mine["67"]=89;
 mine.print_map(); //print all values in mine.
}	