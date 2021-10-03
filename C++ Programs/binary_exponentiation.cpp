#include <bit/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    long long base, exp;
    cin>>base>>exp;

    long long ans = binpow(base, exp);
    cout<<ans<<'\n';
    return 0;
}