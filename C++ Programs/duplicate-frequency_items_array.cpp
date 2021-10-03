#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

#define max_size 100  
int mostFrequent(int arr[], int n) 
{  
    int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[n - 1]; 
    } 
  
    return res; 
} 
int main()
{
    int arr[max_size];
    int i, j, size, count = 0;

    cout<<"Enter size of the array : ";
    cin>>size;

    cout<<"Enter elements in array : ";
    for(i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }
cout<<"\n Total number of duplicate elements found in array = "<<count;
cout<<"\n Most frequently occuring element:";
cout<< mostFrequent(arr, size);
return 0;
}
