// Problem Link - https://codeforces.com/contest/1476/problem/B
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,k,l,m,n,p,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<long long int>v(n);
        for(i=0;i<n;i++)
        {
            cin>>v[i];
        }
        p=v[0];l=0;
        for(i=1;i<n;i++)
        {
            double c = (v[i]*1.0)/p;
            double d = (k*1.0)/100;
            m=0;
            if(c>d)
            {
                m = ceil((v[i]*100)*1.0/k) - p;
                l+=m;
            }
            p+=v[i]+m;
        }
        cout<<l<<"\n";
    }
}
