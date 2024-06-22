#include<iostream>
using namespace std;
#include"make_up.h"
int main(){
Bit<8> bits1={56};
Bit<16>bits2={112};
Bit<8>bit3=bits1 & bits2;
Bit<8>::print_bit_pattern(bit3);
}