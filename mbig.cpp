#include "BigNum.h"
#include <iostream>

int main(){
    BigNum n, n2;
    n.input();
    n.output();
    std::cout << std::endl;
    n.div10(1);
    n.output();
    std::cout << std::endl;

//    n2.input();
//    BigNum n3 = n - n2;
//    n3.output();

    return 0;
}
