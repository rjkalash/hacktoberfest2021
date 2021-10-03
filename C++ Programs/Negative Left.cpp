#include<iostream>
using namespace std;

//function to rearrange element
void move(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

//printing array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Main code
int main()
{
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    move(arr, n);
    printArray(arr, n);
    return 0;
}
