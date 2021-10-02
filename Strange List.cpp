// Problem Link - https://codeforces.com/contest/1471/problem/B
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,k,l,m,n,p,t,a,x,y=1,z;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        vector< pair<long long int,long long int> >v;
        for(i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(make_pair(a,y));
        }
        i=0;z=1;
        while(true)
        {
            if((v[i].first%x)==0)
            {
                v.push_back(make_pair((v[i].first/x),v[i].second*x));
            }
            else
            {
                break;
            }
            i++;
        }
        l=0;
        for(i=0;i<v.size();i++)
        {
            l+=v[i].first*v[i].second;
        }
        cout<<l<<"\n";
        
    }
}
