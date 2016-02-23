#include "BigNum.h"

int main(){
    BigNum n, n2;
    n.input();
    n2.input();
    BigNum n3 = n - n2;
    n3.output();

    return 0;
}
