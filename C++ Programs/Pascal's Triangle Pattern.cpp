//C++ Program to print Pascal's Triangle Pattern.
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the number of rows: ";
  cin>>n;
  for(int row=1; row<=n; row++)
  {
        int a=1;
        for(int s=1; s<=40-row; s++)
        {
            cout<<" ";
        }
        for(int i=1; i<=row; i++)
        {
            cout<<" "<<a;
            a=a*(row-i)/i;
        }
        cout<<endl;
  }
  return 0;
}