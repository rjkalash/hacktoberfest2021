//Longest Palindromic Subsequence
//DP


#include <bits/stdc++.h>
using namespace std;


class Solution{
		

	public:
	int longestPalindromeString(string s) 
	{ 
        int n = s.size();

        if(s.size() == 0)
            return 0;

        //reversing the given string and using it as the 2nd string        
        string t = s;
        reverse(t.begin(), t.end());
        

	    int dp[n+1][n+1];
        
        //using LCS
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
            
        for(int i=1; i<=n; i++)
            dp[0][i] = 0;
            
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        
        return dp[n][n];
	} 
};


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1;

        cin>>s1;

	    Solution ob;
	    cout << ob.longestPalindromeString(s1) << "\n";
	     
    }
    return 0;
}