// Problem Link - https://codeforces.com/contest/1516/problem/B
#include<bits/stdc++.h>
#define int long long int
#define pb push_back
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i,j,k,l,m,n,p,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>v(n);
		p = 0;
		int pref[n];
        for(i=0;i<n;i++)
        {
            cin>>v[i];
			p = p^v[i];
			pref[i] = p;
        }
		// cout<<p<<"\n";
		j = p;
        int suff[n] = {0};
        if(j == 0)cout<<"YES"<<"\n";
        else 
		{
			p = 0;
			for(i=n-1;i>0;i--)
			{
				p = p ^ v[i];
				suff[i] = p;
			}
			// for(i=0;i<n;i++)cout<<suff[i]<<" ";cout<<"\n";
			p = 0;
			l = 0;
			for(i=0;i<n-1;i++)
			{
				p = p ^ v[i];
				// cout<<p<<"\n";
				for(k=n-1;k>i;k--)
				{
					if(suff[k] == p && p == j)
					{
						l = 1;
						break;
					}
				}
			}
			if(l == 1)cout<<"YES"<<"\n";
			else cout<<"NO"<<"\n";
		}	
    }
}
