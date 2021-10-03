/******************************************************************************

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.


question link-https://leetcode.com/problems/longest-common-subsequence/
*******************************************************************************/
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m=text1.size();
      int n=text2.size();
    int L[m + 1][n + 1];
    int i, j;


    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;

        else if (text1[i - 1] == text2[j - 1])
            L[i][j] = L[i - 1][j - 1] + 1;

        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }


    return L[m][n];
}


};
