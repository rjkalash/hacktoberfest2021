#include <bits/stdc++.h>
using namespace std;

int bin_exponent(int a, int b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    if (b & 1)
        return a * bin_exponent(a * a, b >> 1);
    else
        bin_exponent(a * a, b >> 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    // bin_exponent returns a raise to b
    cout << bin_exponent(a, b) << "\n";

    return 0;
}
