#include <bits/stdc++.h>

int64_t binary_exp( int64_t a, int64_t b, int64_t MOD ) {
    a %= MOD;
    int64_t res { 1 };

    while( b ) {
        if( b & 1 )
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

int main() {
    int64_t A, B;
    std::cin >> A >> B;

    std::cout << binary_exp( A, B, 1e9 + 7 ) << std::endl;
}

