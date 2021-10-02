/*
longest Increasing subsequence
Sample : 
N = 8
Array = [1, 6, 4, 8, 3, 2, 11, 7]

dp_array corresponding to the above Array
dp = [1, 2, 2, 3, 2, 2, 4, 3]

hence output is => max ( [1, 2, 2, 3, 2, 2, 4, 3] ) = 4
*/


#include <bits/stdc++.h>
typedef long long ll;
#define all(v) v.begin(), v.end()

// function for fast input and output
void fastInOut() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// function for finding max element b/w two values ( we can also use built in max function in c++ )
inline ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {

    fastInOut();
  
    // size of the vector
    ll N;
    std::cin >> N;
    // vector
    std::vector<ll> V(N);
    for (ll i = 0; i < N; i++)
        std::cin >> V[i];

    std::vector<ll> dp(N, 0);
    // for a single element there is no other element to compare so a single element is always increasing hence dp[ N - 1] that is last element is 1
    dp[N - 1] = 1;
    // for any index i dp[i] contains the number of elements greater than v[i] including the v[i] itself
    // for example if dp[i] = 4 -> this means from index i there are 4 elements greater than v[i] which means v[i] is lesser than them 
    for (ll i = N - 2; i >= 0; i--) {
        // initially x is 0 ( we can also initialize it to 1 ( as we have discussed earlier every single element itself is a incresing sbsequence )
        ll x = 0;
        for (ll j = i + 1; j < N; j++) {
            // if we find some index j for which v[i] is less than v[j] then we take the max of x and dp[j] that v[i] is less than x elements or dp[j] elements
            if (V[i] < V[j])
                x = max(x, dp[j]);
        }
        // we add the number of elements greater than v[i] + 1 ( +1 is for the the number v[i] itself )
        dp[i] = x + 1;
    }
    // printing the maximum of the dp vector
    std::cout << *max_element(all(dp)) << std::endl;
    return 0;
}
