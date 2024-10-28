 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
enum Endianess{
    BIG_ENDIAN=0x02,
    LITTLE_ENDIAN=0x04
};  // Byte order in memory...
typedef vector<int> Byte_Order;
class Endian{
    private:
    bool is_big_endian;
    bool is_little_endian;
    public:
    Endian()=default;
    bool is_Little_endian() const {
        return is_little_endian;
    }
    bool is_Big_endian() const {
        return is_big_endian;
    }
    Byte_Order Construct_Byte_Order(Byte_Order byte_order,Endianess ENDIAN){
        if(ENDIAN==BIG_ENDIAN){
            is_big_endian=true;
            is_little_endian=false;
            return byte_order;
        }
        else if(ENDIAN==LITTLE_ENDIAN){
             is_big_endian=false;
            is_little_endian=true;
            std::reverse(byte_order.begin(),byte_order.end());
            Byte_Order byte;
            for(int i=0;i<byte_order.size();i++){
                byte.push_back(byte_order.at(i));
            }
          return byte;  
        }
            
        }
        
    
};
int main(int argc, char *argv[])
{
	size_t choice=0;
	bool is_reverse;
	 std::vector<int> test={5,4,6,7,9,8};
	do{
	    cout<<"BYTE_ ORDER"<<endl;
	    cout<<"Choose one of the options to get desored result"<<endl;
	    cout<<"1).Little Endian"<<endl;
	    cout<<"2).Big Endian"<<endl;
	    cout<<"3) No option"<<endl;
	    cout<<"4).Display Result"<<endl;
	    cout<<"Enter your choice"<<endl;
	    cin>>choice;
	    
	    Endian edian;
	    Endian edian1;
	    if(choice==1){
	        is_reverse=true;
	        test=edian.Construct_Byte_Order(test,LITTLE_ENDIAN);
	    }
	    else if (choice==2){
	        if(is_reverse==true){
	            std::reverse(test.begin(),test.end());
	        }
	        test=edian1.Construct_Byte_Order(test,BIG_ENDIAN);
	    
	}
	  else if(choice==3){
	      return 1;
	  }
    else if(choice==4){
         if(edian.is_Little_endian()){
             for(int i=0; i<test.size();i++){
                 std::cout<<test.at(i)<<endl;
             }
         }
         else if(edian1.is_Big_endian()){
             for(int i=0;i<test.size();i++){
                 std::cout<<test.at(i)<<endl;
             }
         }
    }
	}
	while(choice!=3);
	
}