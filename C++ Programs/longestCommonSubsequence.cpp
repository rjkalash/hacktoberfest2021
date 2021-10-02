#include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
#define pb push_back

ll LCS(std::string s1, std::string s2, ll m, ll n, std::vector<std::vector<ll>> &dp) {
    if (m == 0 or n == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = 1 + LCS(s1, s2, m - 1, n - 1, dp);
    else
        return dp[m][n] = std::max(LCS(s1, s2, m - 1, n, dp), LCS(s1, s2, m, n - 1, dp));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll T;
    std::cin >> T;
    while (T--) {
        std::string s1, s2;
        std::cin >> s1 >> s2;

        ll m = s1.size(), n = s2.size();
        std::vector<std::vector<ll>> dp(m + 1, std::vector<ll>(n + 1, -1));
        std::cout << LCS(s1, s2, m, n, dp) << "\n";
    }

    return 0;
}
