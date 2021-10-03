// problem link - https://www.codechef.com/LTIME100B/problems/ALBOFACE


#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
const long double Pi = 3.141592653;
const ll mod=1e9+7;
long long INF =1000000000000000000;
struct mycmp
{
    bool operator()(pair<int,int>a,pair<int,int>b)const
    {
        return (a.first<b.first) || (a.first==b.first && a.second>b.second);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        if(n==1)
        {
            cout<<"Alice\n";
        }
        else
        {
            if(n&1LL)
            {
                n=n-1;
                ll cnt=0;
                while(n)
                {
                    ll cnt1=0;
                    while(n%2==0)
                    n=n/2,++cnt1;
                    n=n-1;
                    if(cnt1>=2)
                     ++cnt;
                }
                if(cnt>=2)
                cout<<"Bob\n";
                else
                {
                    if(cnt==0)
                    cout<<"Alice\n";
                    else
                    cout<<"Bob\n";
                }
            }
            else
            {
                ll cnt=0;
                while(n)
                {
                    ll cnt1=0;
                    while(n%2==0)
                    n=n/2,++cnt1;
                    n=n-1;
                    if(cnt1>=2)
                    ++cnt;
                }
                //cout<<cnt<<"\n";
                if(cnt>=2)
                cout<<"Alice\n";
                else
                {
                    if(cnt==0)
                    cout<<"Bob\n";
                    else
                    cout<<"Alice\n";
                }
            }
        }
    }
}
