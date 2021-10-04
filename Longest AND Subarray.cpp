//please accept this as hacktoberfest-accepted label

//problem link

//https://www.codechef.com/OCT21C/problems/ANDSUBAR/
//thanks

//HAPPY CODING


//* Don't Burn Your Opportunities just for Temporary Happiness
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int powerOf2(int n){
    int count=1;
    int power=0;
    while (count<=n)
    {
        count*=2;
        power++;
    }
    return power-1;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int res=powerOf2(n);
        int ans=n-(1<<res)+1;
        while (res>0)
        {
            ans=max(ans,(1<<res)-(1<<(res-1)));
            res--;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
