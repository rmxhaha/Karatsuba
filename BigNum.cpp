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

int BigNum::len(){
    return 1000 - beg();
}

int BigNum::beg(){
    int i = 0;
    for( ; i < 1000 && num[i] == '0'; ++ i );
    return i;
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
    int i = beg();
    if( i == 1000 ){
        std::cout << 0 << std::endl;
    }

    while( i < 1000 ){
        std::cout << num[i];
        ++i;
    }
}

bool BigNum::isZero(){
    return (beg()== 1000);
}

BigNum operator+(const BigNum& a,const BigNum& b){
    //addition table
    BigNum carry;
    BigNum res;

    for( int i = 999; i >= 1; --i ){
        int x = (a.num[i]-'0')+(b.num[i]-'0');
        int n = x % 10;
        int c  = x / 10;
        res.num[i] = '0' + n;
        carry.num[i-1] = '0' + c;
    }

    if( carry.isZero())
        return res;
    else
        return carry + res;
}


BigNum operator-(const BigNum& a,const BigNum& b){
    //addition table
    // use subtract by adding trick
    // https://www.youtube.com/watch?v=PS5p9caXS4U
    BigNum res;
    BigNum carry;

    int i = 0;

    for( ; i < 1000 && b.num[i] == '0' && a.num[i] == '0'; ++ i);
    for( ; i < 999; ++ i ){
        res.num[i] = '9' - b.num[i] + '0';
    }
    res.num[999] = ':' - b.num[i] + '0';
    if( b.num[i] == '0' ){
        carry.num[998] = '1';
        res.num[999] = '0';
    }


    BigNum res2 = res + a + carry;
    i = 0;
    for( ; i < 1000 && res2.num[i] == '0'; ++ i);
    res2.num[i] = '0';
    return res2;
}


void BigNum::div10(int n){
    int b = beg();
    int i = 999;
    int k = i - n;

    while( b <= k ){
        num[i] = num[k];
        k--;
        i--;
    }
    for( ; k <= i; ++k ){
        num[k] = '0';
    }
}

BigNum kali3(const BigNum& a, const BigNum& b, int n){

}

BigNum operator*(const BigNum& a,const BigNum& b){

}
