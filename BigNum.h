#ifndef BIGNUM_H
#define BIGNUM_H

#define L 300
#include <iostream>

class BigNum {
public:
    BigNum();
    ~BigNum();
    BigNum(const BigNum& );


    void input();
    void output();

    friend std::ostream& operator<<(std::ostream& out, const BigNum& b);
    friend std::istream& operator>>(std::istream& in, BigNum& b);

    bool isZero() const;
    int len() const ;
    int beg() const ;
    void div10(int);
    void mod10(int);
    void multiply10(int);

    friend BigNum kali3(const BigNum& a, const BigNum& b);
    friend BigNum operator+(const BigNum& a,const BigNum& b);
    friend BigNum operator-(const BigNum& a,const BigNum& b);
    friend BigNum operator*(const BigNum& a,const BigNum& b);

    friend int compare(const BigNum& a,const BigNum& b); // this doesn't compare the sign
private:
    char num[L];
    bool positive; // false if negative
};



#endif // BIGNUM_H
