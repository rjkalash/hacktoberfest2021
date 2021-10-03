#include <iostream>

/* 
 * Function to calculate A raised to power B (A^B) in O(log B)
 */
int64_t binary_exponentiation( int64_t A, int64_t B ) {
    int64_t res { 1 };

    while( B ) {
        if( B & 1 ) 
            res *= A;

        A *= A;
        B >>= 1;
    }

    return res;
}

/* 
 * Function to calculate (A ^ B) % MOD in O(log B). 
 */
int64_t binary_exponentiation( int64_t A, int64_t B, int64_t MOD ) {
    A %= MOD;
    int64_t res { 1 };

    while( B ) {
        if( B & 1 ) 
            res = res * A % MOD;

        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}

int main() {
    int64_t A, B;

    std::cout << "Enter the value: ";
    std::cin >> A;

    std::cout << "Enter the exponent: ";
    std::cin >> B;

    std::cout << A << "pow" << B << ": " << binary_exponentiation( A, B ) << std::endl;
}


