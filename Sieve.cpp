#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define trav(it, x) for(auto& it : x)

void primeSieve(int n)
{
    int prime[n+1]={0};
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==0)
        cout<<i<<endl;
    }
}
void primefactor(int n)
{
    int spf[n+1]={0};
    for(int i=2;i<=n;i++)
    {
        spf[i]=i;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(spf[j]==j)
                spf[j]=i;
            }
        }
    }
     int count=0;
    while(n!=1)
    {
        cout<<spf[n]<<" ";
        n /= spf[n];
        // count++;
    } 
}
int main  () {
    int n;
    cout<<"Enter the number :-"<<endl;
    cin>>n;
    primefactor(n);
return 0;
}
