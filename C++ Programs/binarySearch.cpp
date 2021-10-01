#include<iostream>
using namespace std;
int binarySearch(int arr[], int n,int key){
    int start=0,end=n-1;

    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
    }
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter arr["<<i<<"]";
        cin>>arr[i];
    }
    int key;
    cout<<"Enter key : ";
    cin>>key;
    int ans=binarySearch(arr,n,key);
    cout<<ans<<endl;
    return 0;
}