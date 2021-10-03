#include <bit/stdc++.h>
using namespace std;

int n;

// Check if n is a prime in O(sqrt(n))
bool prime_check(int n) { 
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

//Sieve of eratosthenes
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

//prime factorization in O(log n)
void prime_fact(){ 
    for(int i=1;i<=n;i++)
        arr[i]=-1;

    for(int i=2;i<=n;i++){
        if(arr[i]==-1){
            for(int j=i;j<=n;j+=i){
                if(arr[j]==-1)
                    arr[j]=i;
            }
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
