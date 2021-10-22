// problem link https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //checking that mid value is a feasuble value or not
    bool isfeasible(int a[], int n, int k, int ans){
        int req=1, sum=0;
        for(int i=0; i<n; i++){
            if(sum+a[i]>ans){
                req++;
                sum=a[i];
            }
            else{
                sum+=a[i];
            }

        }
        return (req<=k);
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int k)
    {int sum=0, mx=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
        mx=max(mx, a[i]);
    }
    int low=mx, high=sum, res=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(isfeasible(a, n, k, mid)){
            res=mid; //if feasible, go to left half
            high=mid-1;

        }
        else{
            low=mid+1; //else go to right half

        }
    }
    return res;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
