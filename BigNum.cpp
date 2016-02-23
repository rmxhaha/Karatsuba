#include "BigNum.h"
#include <cstring>
#include <string>
#include <iostream>


BigNum::BigNum(){
    for( int i = 0; i < 1000; ++ i)
        num[i] = '0';
}

BigNum::~BigNum(){}

BigNum::BigNum(const BigNum& b){
    for( int i = 0; i < 1000; ++ i )
        num[i] = b.num[i];
}

void BigNum::input(){
    std::string str;
    std::getline(std::cin,str);
    int l = str.length();
    if( l > 1000 ) l = 1000;

    int i = 999;
    for( int k = l; k--; --i){
        num[i] = str[k];
    }

    while(i--)
        num[i] = '0';
}

void BigNum::output(){
    int i;
    for( i = 0; i < 1000 && num[i] == '0'; ++i );

    while( i < 1000 ){
        std::cout << num[i];
        ++i;
    }
}

BigNum operator+(const BigNum& a,const BigNum& b){
}

BigNum operator-(const BigNum& a,const BigNum& b){

}

BigNum operator*(const BigNum& a,const BigNum& b){

}
