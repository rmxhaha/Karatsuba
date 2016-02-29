#include "BigNum.h"
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

// this doesn't compare the sign
int compare(const BigNum& a,const BigNum& b){
    int ba = a.beg();
    int bb = b.beg();
    if( ba < bb )
        return -1;
    else if( ba > bb )
        return 1;
    else{
        for( ; bb < L; ++ bb ){
            if( a.num[bb] < b.num[bb] )
                return 1;
            else if( a.num[bb] > b.num[bb] )
                return -1;
        }

        return 0;
    }
}


BigNum::BigNum(){
    for( int i = 0; i < L; ++ i)
        num[i] = '0';
    positive = true;
}

BigNum::~BigNum(){}

BigNum::BigNum(const BigNum& b){
    for( int i = 0; i < L; ++ i )
        num[i] = b.num[i];
    positive = b.positive;
}

int BigNum::len() const {
    return L - beg();
}

int BigNum::beg() const {
    int i = 0;
    for( ; i < L && num[i] == '0'; ++ i );
    return i;
}

std::ostream& operator<<(std::ostream& out, const BigNum& b){
    if( !b.positive ) out << "-";

    int i = b.beg();
    if( i == L ){
        out << 0;
    }
    while( i < L ){
        out << b.num[i];
        ++i;
    }
    return out;
}

std::istream& operator>>(std::istream& in, BigNum& b){
    std::string str;
    in >> str;
    int l = str.length();
    if( l > L ) l = L;

    int i = L-1;
    int flimit;
    if( str[0] == '-' ){
        flimit = 1;
        b.positive = false;
    }
    else {
        flimit = 0;
        b.positive = true;
    }
    for( int k = l; k-- != flimit; --i){
        b.num[i] = str[k];
    }

    while(i--)
        b.num[i] = '0';

    return in;
}

void BigNum::input(){
    std::string str;
    std::getline(std::cin,str);
    int l = str.length();
    if( l > L ) l = L;

    int i = L-1;
    for( int k = l; k--; --i){
        num[i] = str[k];
    }

    while(i--)
        num[i] = '0';
}

void BigNum::output(){
    int i = beg();
    if( i == L ){
        std::cout << 0;
    }

    while( i < L ){
        std::cout << num[i];
        ++i;
    }
}

bool BigNum::isZero() const {
    return (beg()== L);
}

BigNum operator+(const BigNum& a,const BigNum& b){
   if( a.positive ){
        if( b.positive ){
            // do nothing
        }
        else {
            BigNum tb = b;
            tb.positive = true;
            return a-tb;
        }
   }
   else {
        if( b.positive ){
            BigNum ta = a;
            ta.positive = true;
            return b-ta;
        }
        else {
            BigNum ta = a;
            BigNum tb = b;
            ta.positive = true;
            tb.positive = true;
            BigNum r = ta + tb;
            r.positive = false;
            return r;
        }
   }
     //addition table
    BigNum carry;
    BigNum res;

    for( int i = L-1; i >= 1; --i ){
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
    if( a.positive ){
        if( b.positive ){
            if( compare(a,b) == 1 ){ // a < b
                BigNum ta = a;
                BigNum tb = b;
                ta.positive = true;
                tb.positive = true;
                BigNum r = tb-ta;
                r.positive = false;
                return r;
            }
        }
        else { //a - (-b)
            BigNum tb = b;
            tb.positive = true;
            return a+tb;
        }
    }
    else {
        if( b.positive ){ // -a-b
            return a+b;
        }
        else { // -a -(-b)
            BigNum tb = b;
            BigNum ta = a;
            tb.positive = true;
            ta.positive = true;
            return tb - ta;
        }
    }


    //addition table
    // use subtract by adding trick
    // https://www.youtube.com/watch?v=PS5p9caXS4U
    BigNum res;
    BigNum carry;

    int i = 0;

    for( ; i < L && b.num[i] == '0' && a.num[i] == '0'; ++ i);
    for( ; i < L-1; ++ i ){
        res.num[i] = '9' - b.num[i] + '0';
    }
    res.num[L-1] = ':' - b.num[i] + '0';
    if( b.num[L-1] == '0' ){
        carry.num[L-2] = '1';
        res.num[L-1] = '0';
    }

    BigNum res2 = res + a + carry;
    i = 0;
    for( ; i < L && res2.num[i] == '0'; ++ i);
    res2.num[i] = '0';
    return res2;
}


void BigNum::div10(int n){
    int b = beg();
    int i = L-1;
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

void BigNum::mod10(int n){
    int b = beg();
    int i = L-1 - n;
    while( b <= i ){
        num[i] = '0';
        --i;
    }
}

void BigNum::multiply10(int n){
    int k = beg();
    int i = k - n;
    while( k < L ){
        num[i] = num[k];
        ++k;
        ++i;
    }
    while( i < L ){
        num[i] = '0';
        ++i;
    }

}


BigNum kali3(const BigNum& x, const BigNum& y){
    int n = x.len();
    if( n < y.len()) n = y.len();

    if( n <= 1 ){
        int q = (x.num[L-1] - '0')*(y.num[L-1] - '0');
        BigNum b;
        b.num[L-1] = q % 10 + '0';
        b.num[L-2] = q / 10 + '0';

        return b;
    }
    int s = n - n / 2;
    BigNum a(x); a.div10(s);
    BigNum b(x); b.mod10(s);
    BigNum c(y); c.div10(s);
    BigNum d(y); d.mod10(s);

/*
    std::cout << "================\n";
    a.output(); std::cout << std::endl;
    b.output(); std::cout << std::endl;
    c.output(); std::cout << std::endl;
    d.output(); std::cout << std::endl;
    std::cout << "================\n";
*/

    BigNum p = kali3(a,c);
//    std::cout << "p=" ;p.output(); std::cout << std::endl;
    BigNum q = kali3(b,d);
//    std::cout << "q=" ;q.output(); std::cout << std::endl;
    BigNum r = kali3(a+b,c+d);
//    std::cout << "r=" ;r.output(); std::cout << std::endl;
    r = r - p;
//    std::cout << "r=" ;r.output(); std::cout << std::endl;
    r = r - q;
//    std::cout << "r=" ;r.output(); std::cout << std::endl;
    p.multiply10(s*2);
    r.multiply10(s);
//    BigNum sss = kali3(b,d);
//    std::cout << "s=";sss.output(); std::cout << std::endl;
//    std::cout << "================\n";
    return p + q + r;
/*
    BigNum p = kali3(a,c,ss); p.multiply10(n);
    BigNum q = kali3(b,d,ss);
    BigNum r = kali3(a+b,c+d,ss);
    r = r - p - q;
    r.multiply10(ss);


    return p + r + q;
*/}

BigNum operator*(const BigNum& a,const BigNum& b){
    BigNum r = kali3(a,b);
    r.positive = !(!a.positive ^ !b.positive);
    return r;
}
