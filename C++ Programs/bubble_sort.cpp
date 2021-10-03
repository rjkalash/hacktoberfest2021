#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number of elements in integer array:\n";
	cin>>n;
	cout<<"Enter array elements:\n";
	int arr[n];
	//entering array
	for (int i=0; i<n; i++)
		cin>>arr[i];
	//bubble sort
	int temp;
	for (int i=0; i<n; i++)
    {
    	for (int j=0; j<n; j++)
    	{
    		//comparing elements
			if (arr[i]<arr[j])
    		{
    			//swapping compared elements
    			temp = arr[i];
    			arr[i] = arr[j];
    			arr[j] = temp;
			}
		}
	}
	//printing sorted array
	for(int i=0; i<n; i++)
        cout<<arr[i]<<"\t";
	return 0;
}
