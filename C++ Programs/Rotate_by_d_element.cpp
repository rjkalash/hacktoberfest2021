//Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements. 
//Example : 

// Input :  arr[] = [1, 2, 3, 4, 5, 6, 7]
       //  d = 2
//Output : arr[] = [3, 4, 5, 6, 7, 1, 2] 


#include <bits/stdc++.h>
using namespace std;
  
  void reverse(int a[] , int low ,int high)
  {
    while(low<high)
    {
        swap(a[low],a[high]);
        low++;
        high--;
    }

  }

int main()
{
    int n , d;
    cin>>n>>d;
     int a[n];
     for (int i = 0; i < n; ++i)
     {
         cin>>a[i];
     }
     
     reverse(a,0,d-1);
     reverse(a,d,n-1);
     reverse(a,0,n-1);

     for(auto it:a)
     {
        cout<<it<<" ";
     }


    return 0;
}