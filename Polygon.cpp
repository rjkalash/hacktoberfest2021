// Problem Link - https://codeforces.com/contest/1360/problem/E
#include<bits/stdc++.h>
using namespace std;
int A[55][55];
int w[55][55];
int solve(int a,int b,int c)
{
    int x;int y;
    if(a == c || b == c)
    {
        return 1;
    }
    if(A[a][b] == 0)return 0;
    if(w[a][b] != -1)return w[a][b];
     x =  solve(a+1,b,c);
     y =  solve(a,b+1,c);
    return w[a][b] = (x || y);
}
int main()
{
    int i,j,k,l,m,n,p,t;
    cin>>t;
    while(t--)
    {
        memset(w,-1,sizeof(w));
        cin>>n;
        set<string>s;
        vector<string>v(n);
        for(i=0;i<n;i++)
        {
            cin>>v[i];
            s.insert(v[i]);
        }
        if(s.size() == 1)
        {
            cout<<"YES"<<"\n";
        }
        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<v[i].length();j++)
                {
                    A[i][j] = v[i][j] - '0';
                }
            }
            l=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(A[i][j] == 1)
                    {
                        p = solve(i,j,n);
                        // if(p == 1)cout<<i<<" "<<j<<"\n";
                        if(p == 0)
                        {
                            l=1;
                            break;
                        }    
                    }
                }
                if(l == 1)break;
            }
            if(l == 0)cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }    
    }
}
