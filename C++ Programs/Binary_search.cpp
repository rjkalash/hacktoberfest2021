#include <bits/stdc++.h>

int64_t search( const std::vector< int64_t >& val, int64_t low, int64_t high, int64_t target ) {
    while( low < high ) {
        int64_t mid { low + ( high - low ) / 2 };

        if( val[mid] == target ) 
            return mid + 1;

        if( val[mid] > target ) 
            high = mid - 1;

        if( val[mid] < target )
            low = mid + 1;
    }

    return -1;
}

int main() {
    int64_t N;
    std::cout << "Enter the size of the array: ";
    std::cin >> N;

    std::vector< int64_t > val;

    std::cout << "Enter elements in the val array: ";
    for( auto& v : val )
        std::cin >> v;

    int64_t target;
    std::cout << "Enter the value to search in the val array: ";
    std::cin >> target;

    int64_t pos { search( val, 0, N, target ) };

    if( pos == -1 ) {
        std::cout << target << " not found in the val array" << std::endl;
        return 0;
    }

    std::cout << "Found at pos: " << pos << std::endl;
}
