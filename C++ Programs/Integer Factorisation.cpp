#include <bit/stdc++.h>
using namespace std;

vector<long long> trial_division(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main() {
    int n;
    cin>>n;

    vector<long long> factors = trial_division(n);

    for (auto x: factors) {
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}
