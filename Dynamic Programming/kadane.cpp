//Kadane Algorithm
//An efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers that has the largest sum.

#include<bits/stdc++.h>
using namespace std;

int Kadane(int arr[],int size){
    int max_cur=arr[0],max_so_far=arr[0];
  
    for(int i=1;i<size;i++){
        max_cur=max(max_cur+arr[i],arr[i]);
        max_so_far=max(max_cur,max_so_far);
    }
    return max_so_far;
}

int main(){
    int arr[]={-2 ,-3 ,5 ,-1 ,-2 ,1,5 ,-9};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<Kadane(arr,size)<<"\n";
}
