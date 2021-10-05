#include<iostream>
using namespace std;
int main()
{
    int n, i;
    cout<<"Enter the size of the array:  ";
    cin>>n;
   int LA[n];
   cout<<"Enter the elements: \n";
   for(i=0;i<n;i++)
   {
       cin>>LA[i];
   }
   cout <<"The array elements are:\n";

   for(i = 0; i < n; i++)
   {
      cout<<"Element "<<i<<" = " <<LA[i]<<endl;;
   }
}