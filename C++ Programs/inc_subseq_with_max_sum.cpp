#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum[n]={0};
    for(int i=0;i<n;i++)
    {
        sum[i]=arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            sum[i]=max(sum[i],sum[j]+arr[i]);
        }
        cout<<"At i="<<i+1<<" ";
        for(int k=0;k<n;k++)
            cout<<sum[k]<<"\t";
        cout<<"\n";
    }
    int res=*max_element(sum,sum+n);
    cout<<res;
    return 0;
}
