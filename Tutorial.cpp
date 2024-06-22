#include<iostream>
using namespace std;
#include"make_up.h"
int main(){
Bit<8> bits1={56};
Bit<16>bits2={112};
Bit<8>bit3=bits1 & bits2;//operator overloading(I overloaded the bitwise operator and(&))..
Bit<8>::print_bit_pattern(bit3);//it will output "Cast to same size, The sizes are not equal"

Bit<16>bit1={567};
Bit<16>bit2={700};
Bit<16>bit4= bit1 & bit2;
Bit<16>::print_bit_pattern(bit4);// it will output the result of bitwise anding bit1 and bit2
}