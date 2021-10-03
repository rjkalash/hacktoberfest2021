// problem link - https://www.codechef.com/LTIME100B/problems/INTREP


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long

void solve(){
    int n;
    cin >> n;
    if(n%2==0){
        cout << 2*n << " " << n << "\n";
        return;
    }
    else {
        if(n==1){
            cout<<3<<" "<<2<<"\n";
            return;
        }
        else {
            vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
            int found=2;
            for(int i=1;i<20;i++){
                if(n%prime[i]!=0){
                    found=prime[i];
                    break;
                }
            }
            cout << found*n << " " << (found-1)*n << '\n';
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // sieve(1e3);
    cout << fixed << setprecision(10);
    
    int tt=1;
    cin >> tt;
    
    while(tt--){
        solve();
    }
}
