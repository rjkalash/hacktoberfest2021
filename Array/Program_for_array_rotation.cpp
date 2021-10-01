
// C++ program to rotate an array by d elements 
// Contributed by Manogya Rastogi
#include <bits/stdc++.h>
using namespace std;
 
/*Function to left Rotate arr[] of
  size n by 1*/
void leftRotatebyOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
 
    arr[n-1] = temp;
}
 
/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n)
{
    for (int i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}
 
/* utility function to print an array */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
/* Driver program */
int main()
{ int n,d;
  cout<<"Enter size of array";
 cin>> n;
 int arr[n];
 for(int i=0;i<n;i++)
 {
    cin>>arr[i];
 }
 
 //cout<<"Enter number of times leftRotate has be performed";
 cin>>d;
    // Function calling
    leftRotate(arr, d, n);
    printArray(arr, n);
 
    return 0;
}
