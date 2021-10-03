#include <bits/stdc++.h>
 
#define f(a,b,i) for(int i=a;i<b;i++)
#define g(a,b,i) for(int i=b-1;i>=a;i--)
#define int long long
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define mp make_pair
#define CIN(a,x,y) for(int i=x;i<y;i++) cin>>a[i];
#define float double
#define M 1000000007
#define MAX INT_MAX
#define MIN INT_MIN
#define all(a) (a).begin(), (a).end()
//#define N 1010
// #define mp make_pair
using namespace std;
#define fi first
#define sp(n) setprecision(n)
#define se second
#define in insert
#define lb lower_bound
#define ub upper_bound
#define pi pair<int,int>
#define bp(n) __builtin_popcount(n)
#define MAXN 200005
const int N=1e5+10;
const int mod=1000000007;

/*
Input:
5
4
3 1 2 4
3
3 2 1
3
3 1 2
2
1 2
2
2 1
*/

/* 
Output:
1 3 2 4 
1 2 3 
1 3 2 
1 2 
1 2 
*/

void solve() {
    deque<int> dq;
    int n; cin>>n; int a[n]; CIN(a,0,n)
    dq.push_back(a[0]);
    int front = a[0];

    f(1,n,i){
        if(a[i]<=front) {dq.push_front(a[i]); front=a[i];}
        else dq.push_back(a[i]);
    }

    for(auto it: dq) cout<<it<<" ";
    cout<<"\n";
}
 
signed main(){
    FAST_IO
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t; t=1;
    // init();
    cin>>t;
    while(t--){
        //solve();
        solve();
        //if(flag) return 0;
    }
}