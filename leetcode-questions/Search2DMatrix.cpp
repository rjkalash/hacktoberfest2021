// https://leetcode.com/problems/search-a-2d-matrix-ii/
// 240. Search a 2D Matrix II

/*

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/ 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size();
       if (m == 0) return false;
       int n = matrix[0].size();
       int i = 0, j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
       return false;
    }
};
