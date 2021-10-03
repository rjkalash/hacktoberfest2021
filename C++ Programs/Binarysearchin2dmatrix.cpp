#include <bits/stdc++.h>
using namespace std;
//logic:Just as 1d array we want to perform binary search,
//we find mid of row , if key is found we return , else we compare key with last 
//element of that row to check if we need to stay in this row or move to next row
//and we carry on this operaion until we get our element
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = 0;
    int start = 0;
    int end = matrix[0].size()-1;
    int mid;
    while (start <= end && row < matrix.size())
    {
        mid = (start + end) / 2;
        if (matrix[row][mid] == target)
        {
            return true;
        }
        //checking if target or key is greater than current element
        else if (matrix[row][mid] < target)
        {
            //if target is greater than last element of row we move to next row
            if (target > matrix[row][end])
            {
                row++;
            }
            //else me move start
            else
            {
                start=mid+1;
            }
        }
        //if current element is greater than target we move end
        else if (matrix[row][mid] > target)
        {
            end=mid-1;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int New;
            cin >> New;
            temp.push_back(New);
        }
        matrix.push_back(temp);
    }
    int key;
    cin>>key;
    cout<<searchMatrix(matrix,key);
    return 0;
}