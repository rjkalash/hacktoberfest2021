#include <iostream>
#include <climits>
using namespace std;

int maxSubArraySum(int arr[], int length)
{
    // initializing variables
    int max_so_far = 0, max_ending_here = 0;

    // for loop step 4 to 6
    for (int i = 0; i < length; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;

        cout << "For i = " << i;
        cout << "Max_ending_here = " << max_ending_here;
        cout << "Max_so_far = " << max_so_far;
    }
    return max_so_far;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}