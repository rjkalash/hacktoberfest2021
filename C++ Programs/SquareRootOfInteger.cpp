#include <bits/stdc++.h>
using namespace std;

int sqrt(int A) {
    // Base Case
    if(A<=1) return A;
    long long l=0,r=A,mid,x,y;
    while(l<r){
        mid = (l+r)/2; 
        // x and y is used to check for floor value.
        x = mid*mid;
        y = (mid+1)*(mid+1);
        if(x==A||x<A&&y>A) return mid; 
        if(x<A) l=mid+1; 
        else r = mid;
    }
    return l;
}

int main()
{

    int num; cin>>num;
    cout<<sqrt(num);
 
    return 0;
}
