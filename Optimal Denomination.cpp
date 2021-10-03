//problem link - https://www.codechef.com/JULY21C/problems/MINNOTES

#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
const int N=1e6;

int a[N], F[N], B[N];

void gdc(int n2)
{
    F[1] = a[1];
    B[n2] = a[n2];
    for(int i=n2-1; i>0; i--)
    {
        B[i] = __gcd(B[i+1], a[i]);
    }
    for(int i=2; i< n2+1; i++)
    {
        F[i] = __gcd(F[i-1], a[i]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n1;
        cin >> n1;
        int sum=0;
        int ans=0;
        for(int i=1; i<n1+1; i++){
            cin >> a[i];
        }
        sort(a, a+n1+1);
        gdc(n1);
        for(int i=1; i<n1+1; i++){
            sum += a[i];
        }
        int mng = LLONG_MAX;
        for(int i=1; i<n1+1; i++){
            ans = (sum-a[i] + __gcd(F[i-1], B[i+1])) / __gcd(F[i-1], B[i+1]);
            if(ans < mng)
            mng = ans;
        }
        cout << mng << "\n";
    }
    return 0;
}
