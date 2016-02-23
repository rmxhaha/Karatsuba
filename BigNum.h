#ifndef BIGNUM_H
#define BIGNUM_H


class BigNum {
public:
    BigNum();
    ~BigNum();
    BigNum(const BigNum& );


    void input();
    void output();
    bool isZero();
    int len();
    int beg();
    void div10(int);

    friend BigNum kali3(const BigNum& a, const BigNum& b, int n);
    friend BigNum operator+(const BigNum& a,const BigNum& b);
    friend BigNum operator-(const BigNum& a,const BigNum& b);
    friend BigNum operator*(const BigNum& a,const BigNum& b);
private:
    char num[1000];
};



#endif // BIGNUM_H
