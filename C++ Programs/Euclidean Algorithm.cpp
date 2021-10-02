#include <bit/stdc++.h>
using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main() {
    long long a, b;
    cin>>a>>b;

    long long ans = gcd(a, b);
    cout<<ans<<'\n';
    return 0;
}
