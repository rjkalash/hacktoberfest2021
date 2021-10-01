#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the Size of the Array: ";
    cin>>size;

    int currentSum=0;
    int MaxSum=INT_MIN;
    
    int num;
    cin>>num;
    
    while(size--)
    {
      cin>>num;
      currentSum+=num;
      if(currentSum>MaxSum)
        {
            MaxSum=currentSum;
        }
        if(currentSum<0)
        {
            currentSum=0;
        }
    }

    cout<<"Maximum : "<<MaxSum;
}
