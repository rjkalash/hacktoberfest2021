#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
//max element we chose
#define MAX 999999

//matrix chain multiplication program function
int MatrixChainMultiplicationOrder(int arr[], int num)
{
    int min[num][num];
    int i, j, k, l, q;
    for (i = 1; i < num; i++)
    {
        min[i][i] = 0;
    }
    for (l = 2; l < num; l++)
    {
        for (i = 1; i < num - l + 1; i++)
        {
            j = i + l - 1;
            min[i][j] = MAX;
            //replace the number in row or column of matrix
            for (k = i; k <= j - 1; k++)
            {
                q = min[i][k] + min[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < min[i][j])
                {
                    min[i][j] = q;
                }
            }
        }
    }
    return min[1][num - 1];
}

//main function
int main()
{
    //sizes of various matrices
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "\n";
    cout << "Minimum Multiplications Required In Matrix Chain Multiplication Are : " << MatrixChainMultiplicationOrder(arr, size);
    cout << "\n";
    return 0;
}