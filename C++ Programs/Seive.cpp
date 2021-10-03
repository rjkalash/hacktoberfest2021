#include <bit/stdc++.h>
using namespace std;

int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
void seive() {
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    cin>>n;
    seive();

    int m;
    cin>>m;

    for(int i=0; i<m; i++) {
        int num;
        cin>>num;
        if(!is_prime[num]) {
            cout<<"Prime\n";
        }
        else {
            cout<<"Not Prime\n";
        }
    }
    return 0;
}
