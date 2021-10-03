#include <bits/stdc++.h>
using namespace std;

void mergeSort(int input[], int size)
{
    int mid = size / 2;

    if (size == 0 || size == 1)
    {
        return;
    }

    mergeSort(input, mid);
    mergeSort(input + mid, size - mid);

    int sorted[size], j = 0, k = mid;

    for (int i = 0; i < size; i++)
    {
        if ((j < mid) && (k < size))
        {
            if (input[j] < input[k])
            {
                sorted[i] = input[j];
                j++;
            }
            else
            {
                sorted[i] = input[k];
                k++;
            }
        }
        else if (j == mid)
        {
            for (; i < size; i++)
            {
                sorted[i] = input[k];
                k++;
            }
        }
        else
        {
            for (; i < size; i++)
            {
                sorted[i] = input[j];
                j++;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        input[i] = sorted[i];
    }
}




int main()
{
    int length;
    cin >> length;

    int *input = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    mergeSort(input, length);

    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}



// Merge Sort Code
// Send Feedback
// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5
