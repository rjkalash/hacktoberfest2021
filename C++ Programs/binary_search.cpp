#include <iostream>
#include <algorithm>
#include <vector>

int64_t binary_search( const std::vector< int64_t >& val, int64_t low, int64_t high, int64_t target ) {
    while( low < high ) {
        int64_t mid { low + ( high - low ) / 2 };

        // We've found our element. Just return with the pos
        if( val[mid] == target )
            return mid + 1;

        // Value at mid is greater than target. Look for the target in the segment [low...mid)
        if( val[mid] > target )
            high = mid - 1;

        // Value at mid is less than target. Look for the target in the segment (mid, high]
        if( val[mid] < target )
            low = mid + 1;
    }

    return -1;
}

int64_t recursive_binary_search( const std::vector< int64_t >& val, int64_t low, int64_t high, int64_t target ) {
    while( low < high ) {
        int64_t mid { low + ( high - low ) / 2 };

        // We've found our element. Just return with the pos
        if( val[mid] == target )
            return mid + 1;

        // Value at mid is greater than target. Recursively search for the target in the segment [low...mid)
        if( val[mid] > target )
            return recursive_binary_search( val, low, mid - 1, target );

        // Value at mid is less than target. Look for the target in the segment (mid, high]
        if( val[mid] < target )
            return recursive_binary_search( val, mid + 1, high, target );
    }

    return -1;
}

int main() {
    int64_t N;

    std::cout << "Enter the size of the array: ";
    std::cin >> N;

    std::vector< int64_t > vals( N );

    for( int64_t& v : vals )
        std::cin >> v;

    std::sort( vals.begin(), vals.end() );

    int64_t target;
    std::cout << "Enter the value to be searched in the vals array: ";
    std::cin >> target;

    int64_t findPos { binary_search( vals, 0, N, target ) };

    if( findPos == -1 ) {
        std::cout << "Target not present in the vals array" << std::endl;
        return 0;
    }

    std::cout << "Target found at position: " << findPos << std::endl;
}


