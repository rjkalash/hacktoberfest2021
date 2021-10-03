#include <iostream>

int64_t binary_exponentiation( int64_t a, int64_t b ) {
    int64_t res { 1 };

    while( b ) {
        if( b & 1 ) 
            res *= a;

        a *= a;
        b >>= 1;
    }

    return res;
}

int main() {
    int64_t A, B;

    std::cout << "Enter base: ";
    std::cin >> A;

    std::cout << "Enter power: ";
    std::cin >> B;

    std::cout << binary_exponentiation( A, B ) << std::endl;
}
