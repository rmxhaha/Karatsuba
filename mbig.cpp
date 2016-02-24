#include "BigNum.h"
#include <iostream>

int main(){
    int T;
    std::cin >> T;
    while( T-- ){
        BigNum n, n2, n3;
        std::cin >> n >> n2;
        n3 = n * n2;
        std::cout << n3 << std::endl;
    }


//    n2.input();
//    BigNum n3 = n - n2;
//    n3.output();

    return 0;
}
