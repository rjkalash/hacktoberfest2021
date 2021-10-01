/*
Contributed By :- Tejas Bir Singh
Problem Statement
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Solution:- Dynamic Programming
Time Complexity :- O(rows * cols) as we have to travel original matrix for computing DP values 
Space Complexity:- O(rows * cols) as we are using DP matrix for computing subproblems
*/

#include <bits/stdc++.h>
using namespace std;

// this function will return the area of largest square
int maximalSquare(vector<vector<char>> &matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    // this 2D matrix will store the answers of subproblems
    vector<vector<int>> dp(rows, vector<int>(cols));

    /*Base Case:-
        	First row and column cannot form square
        	Copy the original values from first row and col into dp matrix
		*/
    for (int i = 0; i < rows; i++)
    {
        // '0's ASCII value is substracted to map it to integer value
        dp[i][0] = matrix[i][0] - '0';
    }
    for (int j = 0; j < cols; j++)
    {
        dp[0][j] = matrix[0][j] - '0';
    }

    // Core Logic:-
    // start traversing the matrix from 2nd row and col
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {

            // if there is a '1' then check on its top left, left, top sides
            if (matrix[i][j] == '1')
            {
                // get the value of upper row and same col
                int previousRow = dp[i - 1][j];
                // get the value of same row and previous col
                int previousCol = dp[i][j - 1];
                // get the value of previous row and previous col
                int leftDiagonalVal = dp[i - 1][j - 1];

                /*
						the max area can be formed by getting the min out of 
						all 3 side as the smallest value will limit the area 
						of square
                    */
                int minVal = min(previousRow, min(previousCol, leftDiagonalVal));

                // update the DP matrix cell to min val + 1 (1 is added for including current cell)
                dp[i][j] = minVal + 1;
            }
            else
            {
                // if cell is '0' then it cannot be included so set dp[i][j] to 0
                dp[i][j] = 0;
            }
        }
    }

    // traverse over dp matrix to find the max value as it will be the largest length side
    int maxLength = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
        	// update the maxLength if it is smaller than current value
            if (dp[i][j] > maxLength)
            {
                maxLength = dp[i][j];
            }
        }
    }
    // return the square of maxLength to get the max area square
    return (maxLength * maxLength);
}

int main()
{

    // Input Binary matrix of '0's and '1's
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    // call the function to calculate max area of square
    cout << maximalSquare(matrix);
}